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

int modexp(int a, int n, int q){
    if(n<0) return modexp(a,n+(q-1),q);
    else if(n==0) return 1;
    else if(n%2==0) return modexp(a*a,n/2,q);
    else return (a*modexp(a*a,n/2,q))%q;
}
const int N = 5100;
int compute(ll n, int q, vi &fact){
    set<int> facs;
    facs.insert(1);
    facs.insert(n);
    F(i,2,sqrt(n)+10){
        if(n%i==0){
            facs.insert(i);
            facs.insert(n/i);
            break;
        }
    }

    int val=0;
    for(int fac: facs){
        
    }
    return val;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;

    vvi binom(N, vi(N));

    while(t--){
        int l,q;
        cin>>l>>q;
        vi fac(q+1);
        fac[0]=1;
        F(i,1,q+1) fac[i]=(i*fac[i])%q;
        F(i,0,l){
            ll n;
            cin>>n;
            cout<<compute(n, q, fac)<<"\n";
        }
    }
}


