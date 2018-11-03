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
#pragma unused(INF)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }

int issquare(ll a){
    ll sq=round(sqrt(a));
    return sq*sq==a;
}
int main(int argc, const char * argv[]) {
#ifdef local_test
//    input
//    freopen("input","w",stdout);
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int a, b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    int g=__gcd(a,b);
    for(int i=1;i<g;i++){
        if(issquare(g*g-i*i)){
            int j=sqrt(g*g-i*i);
            // A=ki,kj , B=ki-lj,kj+li
            int k=a/g,l=b/g;
            if(k*i-l*j ==0 || k*j+l*i==0) continue;
            cout<<"YES\n0 0\n";
            printf("%d %d\n",k*i,k*j);
            printf("%d %d\n",k*i-l*j,k*j+l*i);
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}

