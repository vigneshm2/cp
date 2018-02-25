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

ll d(int i){
    int esum=0,osum=0,t=0;
    while(i>0){
        int d=i%10;
        i/=10;
        if(d%2) esum+=d;
        else osum+=d;
        t=!t;
    }
    return abs(esum-osum);
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    ll mn=1100000;
    vll dv(2*mn);
    F(i,0,2*mn) dv[i]=d(i);
    vll val(mn);
    val[0]=0;
    vll dvsums(2*mn);
    dvsums[0]=dv[0];
    F(i,1,2*mn) dvsums[i] = dv[i]+dvsums[i-1];
    F(n,1,mn){
        val[n] += 2*(dvsums[2*n-1]-dvsums[n]);
        val[n] += dv[2*n];

        val[n] += val[n-1];
    }
    while(t--){
        int n;
        cin>>n;
        cout<<val[n]<<"\n";
        // 2-> 1 2n->1
        // 3-> 2 2n-1 -> 2
        // n+1 -> n
    }
}


