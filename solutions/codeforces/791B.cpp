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

int dfs(int u, vvi& graph, vi& visited,int c){
    for(int v: graph[u]){
        if(!visited[v]){
            visited[v]=c;
            dfs(v,graph,visited,c);
        }
    }
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    
    vvi graph(n);
    F(i,0,m){
        int u,v;
        cin>>u>>v;
        u--;v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    vi visited(n);
    int c=1;
    F(i,0,n) if(!visited[i]) dfs(i,graph,visited,c++);
    
    vll n_v(n+1);
    vll n_e(n+1);
    F(i,0,n) n_v[visited[i]]++;
    F(u,0,n) for(int v: graph[u]){
        n_e[visited[v]]++;
    }
    // cout<<visited<<"\n";
    // cout<<n_v<<"\n";
    // cout<<n_e<<"\n";
    int ok=true;
    F(i,1,n+1){
        if(!ok) break;
        ll v=n_v[i];
        ll e=n_e[i];
        if((v*(v-1)) != e) ok=false;
    }
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
}


