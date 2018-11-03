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
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 1000000000;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
const ll lmod = 1000000007l;
const int mod=1000000007;
const double eps = 0.000001;
#pragma unused(INF, LINF, PI, lmod, mod, eps)

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

int modpow(ll a, int exp){
    if(exp==0) return 1ll;
    if(exp<0) return modpow(modpow(a,-exp), lmod-2);
    if(exp%2==0) return modpow((a*a) % lmod, exp/2);
    else return (a*modpow((a*a)%lmod, exp/2))%lmod;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vll a(n);
        cin>>a;
        if(n==1) {
            cout<<a[0]<<"\n";
            continue;
        }
        
        vll sums(n);
        ll inv2 = modpow(2, -1);
        F(i,0,n){
            ll pre = (i>0)?sums[i-1]:0;
            ll self = (modpow(2,n-3)*a[i])%lmod;
            sums[i] = (self + ((pre*inv2) % lmod)*a[i]) % lmod;
            if(i==0 || i==n-1) sums[i] = (2*sums[i])%lmod;
        }
        ll sum=0;
        for(ll s: sums) sum = (sum+s)%lmod;
        cout<<sum<<"\n";

    }
}


