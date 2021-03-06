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

ll mod_exp(ll n,int e){
    if(e==0) return 1ll;
    if(e%2==0) return mod_exp((n*n)%mod,e/2);
    else return (n*mod_exp((n*n)%mod,e/2))%mod;
}
ll mod_inv(ll n){
    return mod_exp(n,mod-2);
}
ll binomial(ll n, ll k){
    ll prod=1;
    if(k>n/2) k=n-k;
    F(i,1,k+1){
        prod=(prod*((n-i+1)%mod))%mod;
        prod=(prod*(mod_inv((i)%mod)))%mod;
    }
    return prod;
}
ll binsum(ll n,ll k){
    // (n k+1)=n-k/k+1 (n k)
    ll b=1ll,sum=0ll;
    for(int i=0;i<=k;i++){
        // cout<<i<<" "<<b<<"\n";
        sum=(sum+b)%mod;
        b=(b*(n-i))%mod;
        b=(b*mod_inv(i+1))%mod;
        i++;
        b=(b*(n-i))%mod;
        b=(b*mod_inv(i+1))%mod;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    ll n,k;
    cin>>n>>k;
    // ll sum=0;
    // ll tot = mod_exp(2,n-1);
    // if(n>k/2){
    //     sum=tot;
    //     int st=n;
    //     if(n%2==1) st--;
    //     for(int i=n;i>k;i-=2) sum-=binomial(n,i);
    // } else {
    //     for(int i=0;i<=k;i+=2) sum+=binomial(n,i);
    // }
    cout<<binsum(n,k);
}


