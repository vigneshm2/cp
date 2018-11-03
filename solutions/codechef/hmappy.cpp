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

int checkC(ll c, vi &a, vi &b, ll m){
    int n = a.size();
    F(i,0,n){
        ll diff = c/b[i];
        ll x = a[i]-diff;
        if(x<0) x=0;
        m -= x;
    }
    return (m>=0);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    int n;ll m;
    cin>>n>>m;
    vi a(n), b(n);
    cin>>a>>b;

    int minc=1;
    for(int c=100; c>=0; c--){
        if(checkC(c, a, b, m)) minc=c; 
    }

    //over ints - gives last index where check returns false.
    ll l=0,r=1000000000ll*1000000000ll,mid;
    while(l<r){
        mid=l+(r-l+1)/2;
        if(checkC(mid, a, b, m)) r=mid-1;
        else l=mid;
    }
    
    cout<<l+1<<"\n";
}


