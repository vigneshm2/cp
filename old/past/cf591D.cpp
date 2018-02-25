//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int INF = 1000000000;
const double PI =3.141592653589793238;
#pragma unused(INF,PI)
#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }

double x1[2],x2[2],vmax,t;
double v[2],w[2];
const double eps=1e-7;
double dist(double a[],double b[]){
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}
int check(double time){
    // vt+wt=r
    double wt[2];
    if(time>t){
        F(i,0,2) wt[i]=x1[i]+v[i]*t+w[i]*(time-t);
    } else {
        F(i,0,2) wt[i]=x1[i]+v[i]*time;
    }
    return dist(wt,x2)<=vmax*time;
}
int main(int argc, const char * argv[]) {
#ifdef local_test
//    input
//    freopen("input","w",stdout);
//    cout<<"1 \n 100 10 \n";
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    
    F(i,0,2) cin>>x1[i];
    F(i,0,2) cin>>x2[i];
    cin>>vmax>>t;
    F(i,0,2) cin>>v[i];
    F(i,0,2) cin>>w[i];
    
    double l=eps,r=10000.0/eps;
    while(abs(r-l)>eps){
        double mid=(l+r)/2.0;
        if(check(mid)){
            r=mid;
        } else {
            l=mid+eps;
        }
    }
    if(check(r)) printf("%.7lf",r);
    else printf("-1");
}

