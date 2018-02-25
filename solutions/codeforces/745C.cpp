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

int n,m,k;
vi is_gov;
vvi graph;
vi visited;
vi comp;

int dfs(int u, int c){
    comp[u]=c;
    visited[u]=true;
    for(int v: graph[u]){
        if(!visited[v])
            dfs(v,c);
    }
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    cin>>n>>m>>k;
    
    graph = vvi(n);
    is_gov = vi(n);
    visited = vi(n);
    comp = vi(n);
    
    F(i,0,k){
        int g;
        cin>>g;
        is_gov[g-1]=true;
    }
    F(i,0,m){
        int u,v;
        cin>>u>>v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int nc=0;
    F(i,0,n){
        if(!visited[i]) dfs(i,nc++);
    }
    
    vi is_gov_comp(nc);
    F(i,0,n){
        if(is_gov[i]) is_gov_comp[comp[i]]=true;
    }
    vi comp_count(nc);
    F(i,0,n) comp_count[comp[i]]++;
    
    int max_gov_comp=-1, maxv=-1;
    F(i,0,nc){
        if(is_gov_comp[i] && comp_count[i]>maxv){
            maxv=comp_count[i];
            max_gov_comp=i;
        }
    }
    
    F(i,0,nc){
        if(!is_gov_comp[i]){
            comp_count[max_gov_comp] += comp_count[i];
            comp_count[i] = 0;
        }
    }
    
    cout<<comp<<"\n";
    
    ll comp_edges=0;
    F(i,0,nc){
        ll cc=comp_count[i];
        comp_edges += (cc*(cc-1))/2;
    }
    
    cout<<comp_edges-m<<"\n";
}


