#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

#define F(i,a,n) for(int i=(a);(i)<(n);(i)++)

vector<int> visited;
vector<vector<int> > graph;

void dfs(int u,int c){
    visited[u]=c;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(!visited[v]){
            dfs(v,c);
        }
    }
}
int main(){
    int n;
    cin>>n;
    string namels;
    cin>>namels;
    map<string,int> names;
    vector<string> namesr;
    size_t curr=0,next;
    F(i,0,n){
        next=namels.find_first_of(" ,",curr);
        string name=namels.substr(curr,next-curr);
        names[name]=i;
        namesr.push_back(name);
        curr=next+1;
    }
    int m;
    cin>>m;
    graph=vector<vector<int> >(n,vector<int>());
    visited=vector<int>(n,0);
    F(i,0,m){
        string edge;
        cin>>edge;
        next=namels.find_first_of(" ,",0);
        string s1=edge.substr(0,next);
        int i1=names[s1];
        string s2=edge.substr(next+1);
        int i2=names[s2];
        graph[i1].push_back(i2);
        graph[i2].push_back(i1);
    }
    int cc=1;
    F(i,0,n){
        if(visited[i]==0) dfs(i,cc),cc++;
    }
    cout<<cc -1<<"\n";
    F(i,0,n) cout<<i<<" "<<visited[i]<<" "<<namesr[i]<<"\n";
    vector<vector<int> > ccbins(cc,vector<int>());
    F(i,0,n){
        ccbins[visited[i]].push_back(i);
    }
    F(i,1,cc){
        int cs =ccbins[i].size();
        F(j,0,cs){
            cout<<namesr[ccbins[i][j]]<<((j==cs-1)?"\n":",");
        }
    }
}
