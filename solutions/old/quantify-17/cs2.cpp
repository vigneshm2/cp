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


int i_lgn(int n){
    return (int)(2+log(n)/log(2));
}
void util_dfs(int u, vvii &graph, int n, vi &parent, vi &level){
    // fills parent, level - intially parent=-1, level=0
    for(ii ve: graph[u]){
        int v=ve.first;
        if(parent[v]!=-1) continue;
        parent[v]=u;
        level[v]=level[u]+1;
        util_dfs(v, graph, n, parent, level);
    }

}
vvi ancestors(vvii &graph, int n, vi &parent){
    int lgn = i_lgn(n);
    vvi ancestors(n,vi(lgn, -2)); // ancestors[v][x] = 2^x'th ancestor of v
    F(i,0,n) ancestors[i][0] = parent[i]; // 1'th ancestor
    F(k,1,lgn){
        F(i,0,n){
            int pa = ancestors[i][k-1];
            if(pa<0) ancestors[i][k] = pa;
            else ancestors[i][k] = ancestors[pa][k-1];
        }
    }
    return ancestors;
}

int lcs(int u, int v, int n,vvi &ancestors, vvi &level){
    // ensure level(u) <= level(v)
    if(level[u] > level[v]) swap(u,v);
    // make level[u] = level[v]
    int height = i_lgn(n)-1;
    while(level[u] < level[v]){
        int newu = ancestors[u][height];
        if(newu >= 0 && level[newu] <= level[v])
            u = newu;
    }
    return u;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    vvii graph(n);
    F(i,0,n){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        graph[u].pb(mp(v,w));
        graph[v].pb(mp(u,w));
    }

    vi parent(n,-1);
    vi level(n,0);
    parent[0]=-2;
    level[0]=0;
    util_dfs(0, graph, n, parent, level);

}


