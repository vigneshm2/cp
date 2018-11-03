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

vvi grid;
int n,m,k1,k2;

vvi bfs(ii start, int k){
    vvi visited(n,vi(m,-1));
    queue<ii> q;
    q.push(start);
    int x=start.first, y=start.second;
    visited[x][y]=0;
    while(!q.empty()){
        auto top = q.front();q.pop();
        int x=top.first, y=top.second;
        for(int st_x=max(0,x-k);st_x<=min(n-1,x+k);st_x++){
            int md=k-abs(st_x-x);
            for(int st_y=max(0,y-md);st_y<=min(m-1,y+md);st_y++){
                if(md-abs(st_y-y)<0) continue;
                if(grid[st_x][st_y]) continue;
                if(visited[st_x][st_y]==-1){
                    visited[st_x][st_y] = visited[x][y]+1;
                    q.push(mp(st_x,st_y));
                }
            }
        }
    }
    return visited;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    F(tc,0,t){
        
        cin>>n>>m>>k1>>k2;
        grid = vvi(n,vi(m));
        F(i,0,n) F(j,0,m) cin>>grid[i][j];
        vvi v1 = bfs(mp(0,0),k1);
        vvi v2 = bfs(mp(0,m-1),k2);
        // for(vi a:v1) cout<<a<<"\n";
        // for(vi a:v2) cout<<a<<"\n";
        int mind=INF;
        F(i,0,n) F(j,0,m){
            if(v1[i][j]>=0 && v2[i][j]>=0) mind=min(mind,max(v1[i][j],v2[i][j]));
        }
        if(mind==INF){
            cout<<"-1\n";
        } else {
            cout<<mind<<"\n";
        }
    }
}


