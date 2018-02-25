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
typedef vector<ll> vi;
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

int n;
vvi graph;
vi a;

vi visited;
vi weight;
vi parent;
vi max_child_weight;
vi max_pair_weight;

void dfs(int u){
    visited[u]=true;
    weight[u]=a[u];
    ll max1, max2;
    max1=max2=-LINF;
    for(int v: graph[u]){
        if(!visited[v]){
            parent[v]=u;
            dfs(v);
            weight[u]+=weight[v];
            ll maxc = max_child_weight[v];
            max_child_weight[u]=max(max_child_weight[u], maxc);
            max_pair_weight[u]=max(max_pair_weight[u], max_pair_weight[v]);
            if(maxc>=max1) max2=max1,max1=maxc;
            else if(maxc>=max2) max2=maxc;
        }
    }
    if(max1>-LINF && max2>-LINF) 
        max_pair_weight[u]=max(max_pair_weight[u],max1+max2);
    max_child_weight[u]=max(max_child_weight[u], weight[u]);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    cin>>n;
    a.resize(n);
    cin>>a;
    graph.resize(n);
    
    F(i,0,n-1){
        int u,v;
        cin>>u>>v;
        u--;v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    visited = vi(n);
    parent = vi(n,-1);
    weight = vi(n);
    max_child_weight = vi(n,-LINF);
    max_pair_weight = vi(n,-LINF);
    dfs(0);
    
    if(max_pair_weight[0]==-LINF)
        cout<<"Impossible\n";
    else
        cout<<max_pair_weight[0]<<"\n";
    
    // F(i,0,n){
    //     cout<<i<<" - "<<a[i]<<" , "<<weight[i]<<" , "<<max_child_weight[i]<<" : "<<max_pair_weight[i]<<"\n";
    // }
}


