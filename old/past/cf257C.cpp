//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int INF = 1000000000;
const double PI =3.141592653589793238;
#pragma unused(INF,PI)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }

int issquare(ll a){
    ll sq=round(sqrt(a));
    return sq*sq==a;
}
double diff(double d1,double d2){
    double d=abs(d1-d2);
    if(d>180.0) d=360.0-d;
    return d;
}
int main(int argc, const char * argv[]) {
#ifdef local_test
//    input
//    freopen("input","w",stdout);
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n;
    cin>>n;
    vector<double> degrees;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        degrees.push_back(atan2(x,y)*180.0/PI);
    }
    sort(degrees.begin(),degrees.end());
    double mdiff=INF;
//    cout<<degrees<<"\n";
    for(int i=0;i<n-1;i++){
        mdiff=min(360-(degrees[i+1]-degrees[i]),mdiff);
    }
    mdiff=min(degrees[n-1]-degrees[0],mdiff);
    printf("%.12f",mdiff);
}

