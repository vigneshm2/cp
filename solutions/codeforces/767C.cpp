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

vvi graph;
vi cost;
vi subtree_cost;

void dfs(int u, vi& visited){
    if(visited[u]) return;
    subtree_cost[u] = cost[u];
    visited[u] = 1;
    for(int v: graph[u]){
        if(!visited[v]){
            dfs(v, visited);
            subtree_cost[u] += subtree_cost[v];
        }
    }
}

int get_one_target(int u, int target, vi& visited,int inc=true){
    // finds a child node with subset sum = target, -1 otherwise
    if(inc && subtree_cost[u]==target)
        return u;
    visited[u] = 1;
    for(int v: graph[u]){
        int t=-1;
        if(!visited[v])
            t = get_one_target(v, target, visited);
        if(t!=-1) return t;
    }
    return -1;
}

ii get_twowithone_target(int u, int target, vi& visited,int inc=true){
    // finds a node with cost 2*target with child target.
    if(inc && subtree_cost[u]==2*target)
        return mp(u,get_one_target(u, target, visited, false));
    visited[u] = 1;
    ii t=mp(-1,-1);
    for(int v: graph[u]){
        if(!visited[v])
            t = get_twowithone_target(v, target, visited);
        if(t.second!=-1) return t;
    }
    return mp(-1,-1);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    int root;
    graph = vvi(n);
    cost = vi(n);
    subtree_cost = vi(n);
    vi visited(n);
    
    F(i,0,n){
        int p,c;
        cin>>p>>c;
        p--;
        // c+=127;
        if(p==-1) root=i;
        else graph[p].pb(i);
        cost[i]=c;
    }
    
    dfs(root, visited);
    // cout<<subtree_cost<<"\n";
    
    int tot = subtree_cost[root];
    if(tot%3!=0){
        cout<<"-1";
        return 0;
    }
    int target = tot/3;
    // either 2 disjoint subtrees with sum = target
    // or one with sum = 2*target and child subtree with sum = target
    
    vi eq_target;
    visited = vi(n);
    visited[root]=1;
    for(int u: graph[root]){
        int t = get_one_target(u, target, visited);
        if(t!=-1) eq_target.pb(t);
    }
    if(eq_target.size()>=2){
        cout<<eq_target[0]+1<<" ";
        cout<<eq_target[1]+1<<"\n";
        return 0;
    }
    
    visited = vi(n);
    ii t = get_twowithone_target(root, target, visited, false);
    if(t.second!=-1){
        cout<<t.first+1<<" ";
        cout<<t.second+1<<"\n";
        return 0;
    }
    
    cout<<"-1";
}


