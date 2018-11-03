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
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

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

vector<int> low,idx,visited;
int counter=0,scc_counter=0;
vector<vector<int>> graph;
vector<int> scc,scc_stack;
void find_scc(int u){
    low[u]=idx[u]=counter++;
    scc_stack.push_back(u);
    for(int v:graph[u]){
        if(idx[v]==-1){
            visited[v]=1;
            find_scc(v);
        }
        if(visited[v])
            low[u]=min(low[u],low[v]);
    }
    if(low[u]==idx[u]){
        scc_counter++;
        while(1){
            int v=scc_stack.back();
            scc_stack.pop_back();
            visited[v]=0;
            scc[v]=scc_counter;
            if(u==v) break;
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
    
    vi state(n);
    cin>>state;
    
    vvi ds(n);
    
    F(i,0,m){
        int d;
        cin>>d;
        F(j,0,d){
            int dd;
            cin>>dd;
            ds[dd-1].pb(i);
        }
        
    }
    
    
    
    
    graph = vvi(2*m);
    // x_i = i , x_i' = m+i
    F(i,0,n){
        int a=ds[i][0],b=ds[i][1];
        if(state[i]==1){
            graph[a].pb(b);
            graph[b].pb(a);
            graph[m+a].pb(m+b);
            graph[m+b].pb(m+a);
        } else {
            graph[a].pb(m+b);
            graph[b].pb(m+a);
            graph[m+a].pb(b);
            graph[m+b].pb(a);
        }
    }
    
    
    visited = vi(2*m);
    low = vi(2*m,-1);
    idx = vi(2*m,-1);
    scc = vi(2*m);
    
    for(int i=0;i<2*m;i++){
        if(idx[i]==-1){
            visited[i]=1;
            find_scc(i);
        }
    }
    
    int ok=true;
    F(i,0,m){
        if(scc[i]==scc[m+i]) {
            ok=false;
            break;
        }
    }
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
    
    // cout<<"graph\n";
    // F(i,0,2*m) cout<<graph[i]<<"\n";
    // cout<<"scc "<<scc<<"\n";
}


