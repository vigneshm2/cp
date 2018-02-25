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
    while(1){
        int n,m;
        cin>>n>>m;
        if(n==0) break;
        graph=vector<vi>(n,vi());
        dfs_num=vi(n,-1);
        dfs_low=vi(n,-1);
        visited=vi(n,0);
        parent=vi(n,-1);
        scc=vi(n,-1);
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
//        cout<<scc<<"\n";
//        cout<<outdegree<<"\n";
        for(int i=0;i<n;i++){
            if(outdegree[scc[i]]==0) cout<<i+1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

