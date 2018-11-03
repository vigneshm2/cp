//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <numeric>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int INF = 1000000000;
const ll LINF = 1e18+10;
const double PI =3.141592653589793238;
const int mod=1000000007;
const double eps = 0.000001;
#pragma unused(INF,LINF,PI,mod,eps)

#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){
    for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

ll modexp(ll a,ll exp,ll m){
    if(exp==0) return 1ll;
    if(exp%2==0) return modexp((a*a)%m,exp/2,m);
    else return (a*modexp((a*a)%m,exp/2,m))%m;
}
ll modinv(ll a,ll m){
    return modexp(a,m-2,m);
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n,m,d,D;
        cin>>n>>m>>d>>D;
        vvi g(n,vi());
        vi deg(n);
        // map v to v+i for 0<=i<=d
        F(i,0,n) F(j,0,d) {
            m--;
            g[i].pb((i+j)%n);
            deg[(i+j)%n]++;
        }
        // try to fit others
        for(int j=d;j<D;j++){
            if(m==0) break;
            F(i,0,n){
                if(m==0) break;
                m--;
                g[i].pb((i+j)%n);
                deg[(i+j)%n]++;
            }
        }
        int err=0;
        if(m>0) err=1;
        F(i,0,n) if(deg[i]>D) err=1;
        if(err){
            cout<<"-1\n";
        } else {
            F(i,0,n) F(j,0,g[i].size()) printf("%d %d\n",i+1,g[i][j]+1);
        }
    }
}
