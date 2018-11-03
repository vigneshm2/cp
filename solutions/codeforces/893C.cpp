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

void dfs(int u,int c, vvi &g, vi &col){
    col[u]=c;
    for(int v: g[u]){
        if(!col[v]) dfs(v,c,g,col);
    }
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;
    vi c(n);
    cin>>c;

    vvi g(n);
    F(i,0,m){
        int x,y;
        cin>>x>>y;
        x--;y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    vi col(n);
    int nc=1;
    F(i,0,n) if(!col[i]) dfs(i,nc++,g,col);

    vi cost(nc, INF);cost[0]=0;
    F(i,0,n) cost[col[i]] = min(cost[col[i]], c[i]);

    //cout<<col<<"\n"<<nc<<"\n"<<cost<<"\n";

    ll sum=0;
    F(i,0,nc) sum+=cost[i];
    cout<<sum<<"\n";
}



