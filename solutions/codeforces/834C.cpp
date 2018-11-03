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

/*
 * m = 2a+b
 * n = 2b+a
 * Given m,n is it possible with a>=0, b>=0
 *
 * a+b = (m+n)/3
 * a=(2m-n)/3
 * b=(2n-m)/3
 * Conditions: (m+n) divides 3, 2m>=n, 2n>=m
 */

/*
 * p divides one -> p^2 divides atleast one
 * check primes <=10^3
*/
int check(int m, int n){
    if(m<0 || n<0) return false;
    if((m+n)%3 !=0) return false;
    if(2*m<n || 2*n<m) return false;
    return true;
}

vi primes(){
    int n = 32000;
    vi sieve(n,1);
    sieve[0]=sieve[1]=0;
    F(i,0,n) if(sieve[i]) for(int j=2*i;j<n;j+=i) sieve[j]=0;

    vi ps;
    F(i,0,n) if(sieve[i]) ps.pb(i);
    return ps;
}

vi factorize(int n, vi& primes){
    int np = primes.size();
    vi factors(np);
    F(i,0,np){
        if(n==1) return factors;
        while(n%primes[i] == 0){
            //printf("rem %d %d\n",n,i);
            n/=primes[i];
            factors[i]++;
        }
    }
        if(n==1) return factors;
    factors[0]=-1;
    return factors;
}

int check_factors(vi& a, vi& b){
    F(i,0,a.size()) if(!check(a[i], b[i])) {
        //cout<<"error at "<<i<<"\n";
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    vi prs = primes();
    //cout<<*(prs.end()-1);
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        vi fa = factorize(a, prs);
        vi fb = factorize(b, prs);

        if(check_factors(fa, fb))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}


