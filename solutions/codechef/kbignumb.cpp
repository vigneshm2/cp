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

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 1000000000;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
const int mod=1000000007;
const double eps = 0.000001;

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

ll modexp(ll a, ll exp, ll mod){
    if(exp==0) return 1;
    if(exp%2==0) return modexp((a*a)%mod,exp/2,mod);
    else return (a*modexp((a*a)%mod,exp/2,mod))%mod;
}

int ndigs(ll a){
    int d=0;
    while(a>0) d++,a/=10;
    return d;
}

ll naive(ll a,ll n, ll m){
    ll val=0;
    ll p10b=modexp(10,ndigs(a),m),p10=1;
    // cout<<p10b<<"\n";
    F(i,0,n){
        val=(val+p10*a)%m;
        p10=(p10*p10b)%m;
    }
    return val;
}
ll repmod(int sz, ll n, ll m){
    // find 1+10^sz+10^2sz+...10^(n-1)sz % m
    if(n==1) return 1;
    if(n%2==0){
        // (1+10^sz..+10^(n/2-1))(1+10^n/2)
        ll mult=modexp(10,(n/2)*sz,m);
        mult=(mult+1)%m;
        return (repmod(sz,n/2,m)*mult)%m;
    } else {
        // 1+10^sz+...10^(n-2)sz + 10^(n-1)sz
        return (repmod(sz,n-1,m)+modexp(10,(n-1)*sz,m))%m;
    }
}
ll logn(ll a, ll n, ll m){
    return (a*repmod(ndigs(a),n,m))%m;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        ll a,n,m;
        cin>>a>>n>>m;
        // cout<<naive(a,n,m)<<"\n";
        cout<<logn(a,n,m)<<"\n";
    }
    
}


