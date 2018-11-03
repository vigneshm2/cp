//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int INF = 1000000000;
const double PI =3.141592653589793238;
#pragma unused(INF,PI)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }

vector<vi> graph;
vi dfs_num,dfs_low;
vi visited,parent;
vector<ii> cut_edges;
set<int> cut_vertices;
int dfs_count=0,root=0,rootchildren=0;
void dfs(int u){
    dfs_num[u]=dfs_low[u]=dfs_count++;
    visited[u]=1;
    for(int v:graph[u]){
        if(!visited[v]){
            visited[v]=1;
            parent[v]=u;
            if(u==root) rootchildren++;
            dfs(v);
            if(dfs_low[v]>dfs_num[u]){
                cut_edges.push_back(make_pair(min(u,v), max(u,v)));
            }
            if(dfs_low[v]>=dfs_num[u]){
                cut_vertices.insert(u);
            }
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        } else {
            // back edge
            if(parent[u]!=v) dfs_low[u]=min(dfs_low[u],dfs_num[v]);
        }
    }
}

int main(int argc, const char * argv[]) {
#ifdef local_test
//    input
    freopen("input","w",stdout);
    cout<<"6 5 \n 0 1 1 2 4 3 1 4 4 5";
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n,m;
    scanf("%d %d",&n,&m);
    graph.resize(n,vi());
    dfs_num.resize(n,0);
    dfs_low.resize(n,0);
    visited.resize(n,0);
    parent.resize(n,0);
    cut_edges.clear();
    cut_vertices.clear();
    dfs_count=0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<n;i++) {
        if(!visited[i]){
            root=i;
            rootchildren=0;
            dfs(i);
            if(rootchildren>1) cut_vertices.insert(i);
            else cut_vertices.erase(i);
        }
    }
    vector<vi> scc;
    for(int i=0;i<n;i++){
        while(scc.size()<=dfs_low[i]) scc.push_back(vi());
        scc[dfs_low[i]].push_back(i);
    }
//    cout<<dfs_low<<"\n"<<dfs_num<<"\n";
    cout<<cut_edges<<"\n";
    cout<<cut_vertices<<"\n";
    for(int i=0;i<scc.size();i++) cout<<i<<" "<<scc[i]<<"\n";
}

