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

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    // state - (idx, num got)
    // f(idx,got) = min(f(idx-j,got-1)+cost(i,j,got-1), f(idx-j,got) + cost(i,j,got))
    // f(idx+1,got) = f(idx,got)+(got)*k
    // if b[i], f(idx+1,got+1) = f(idx,got) + (got+1)*k
    // find f(n,m)
    // 2*n*n*m
    int n,m,k;
    cin>>n>>m>>k;
    vi b(n);
    cin>>b;

    vvi f(n+1,vi(m+1, INF));
    f[0][0]=0;
    //F(i,0,n) F(j,0,m+1) {
        //printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        //f[i+1][j] = min(f[i+1][j], f[i][j] + j*k);
        //if(b[i] && j<m) f[i+1][j+1] = min(f[i+1][j+1], f[i][j] + (j+1)*k);
    //}
    F(i,1,n){
        // fill f[i]
        // do nothing
        F(j,0,m+1) f[i][j] = min(f[i][j], f[i-1][j] + max(1, j*k));
        // pick up
        F(j,1,m+1) if(b[i]) f[i][j] = min(f[i][j], f[i-1][j-1] + max(1, (j-1)*k)); 
    }

    //F(i,0,n) cout<<f[i]<<"\n";

    int minc=INF;
    F(i,0,n) minc=min(minc, f[i][m]);
    if(minc >= INF) minc = -1;
    cout<<minc<<"\n";
}


