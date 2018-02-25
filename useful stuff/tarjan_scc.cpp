//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <stack>
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

vi dfs_num,dfs_low,visited,parent,scc;
vector<vi> graph;
stack<int> vertex_stack;
int dfs_count=0,scc_count=0;

void dfs(int u){
    visited[u]=1;
    vertex_stack.push(u);
    dfs_num[u]=dfs_low[u]=dfs_count++;
    for(int v:graph[u]){
        if(dfs_num[v]==-1)
            dfs(v);
        if(visited[v])
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u]==dfs_num[u]){
        while(!vertex_stack.empty()){
            int v=vertex_stack.top();vertex_stack.pop();
            scc[v]=scc_count;
            visited[v]=0;
            if(v==u) break;
        }
        scc_count++;
    }
}

int main(int argc, const char * argv[]) {
#ifdef local_test
//    input
//    freopen("input","w",stdout);
//    cout<<"6 5 \n 0 1 1 2 4 3 1 4 4 5";
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n,m;
    cin>>n>>m;
    graph.resize(n,vi());
    dfs_num.resize(n,-1);
    dfs_low.resize(n,-1);
    visited.resize(n,0);
    parent.resize(n,-1);
    scc.resize(n,-1);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b--;
        graph[a].push_back(b);
    }
    for(int i=0;i<n;i++) if(dfs_num[i]==-1) dfs(i);
    vi outdegree(scc_count,0);
    for(int i=0;i<n;i++){
        for(int j:graph[i]){
            if(scc[i]!=scc[j]){
                outdegree[scc[i]]++;
            }
        }
    }
//    cout<<scc<<"\n";
//    cout<<outdegree<<"\n";
    int n0=0;
    for(int deg:outdegree) n0+=(deg==0);
    int capc=-1;
    if(n0==1){
        for(int i=0;i<scc_count;i++) if(outdegree[i]==0) capc=i;
        vi caps;
        for(int i=0;i<n;i++) if(scc[i]==capc) caps.push_back(i+1);
        cout<<caps.size()<<"\n"<<caps;
    } else {
        cout<<0;
    }
}

