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
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int INF = 1000000000;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
#pragma unused(INF,PI)
#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){
    for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

int n,m;
vector<set<int> > graph;
vector<string> grid;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int in(int x,int y){
    return (x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#');
}
int vertex(int x,int y,char c){
    if(c=='.')
        return y+m*x+3;
    else
        return c-'1';
}
vi bfs(int root){
    vi dist(graph.size(),INF);
    queue<int> q;
    q.push(root);
    dist[root]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:graph[u]){
            if(dist[v]==INF){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}
int main(int argc, const char * argv[]) {
#ifdef local_test
//    input
//    freopen("input","w",stdout);
//    cout<<"1 \n 100 10 \n";
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    cin>>n>>m;
    grid=vector<string>(n);
    F(i,0,n) cin>>grid[i];
    graph=vector<set<int>>(n*m+3,set<int>()); // 0,1,2 are state nodes
    F(i,0,n) F(j,0,m){
        int v=vertex(i,j,grid[i][j]);
        if(grid[i][j]!='#'){
            F(d,0,4){
                if(in(i+dir[d][0],j+dir[d][1])){
                    int u=vertex(i+dir[d][0],j+dir[d][1],grid[i+dir[d][0]][j+dir[d][1]]);
                    graph[u].insert(v);
                }
            }
        }
    }
    vi dists[3];
    F(i,0,3) dists[i]=bfs(i);
    //F(i,0,3) cout<<dists[i]<<"\n";
    ll mindist=LINF,idx=-1;
    F(i,0,graph.size()) {
        mindist=min(mindist,(ll)dists[0][i]+dists[1][i]+dists[2][i]);
    }
    if(mindist>=INF) mindist=1;
    cout<<mindist-2<<"\n";
}

