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

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,e;
    cin>>n>>e;
    vector<multiset<int>> graph(n);
    vi deg(n);
    map<ii, int> edges;
    F(i,0,e){
        int a,b;
        cin>>a>>b;
        a--;b--;
        graph[a].insert(b);
        graph[b].insert(a);
        deg[a]++;
        deg[b]++;
        edges[mp(a,b)] = i;
    }
    vi vis(n);
    //bfs
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v: graph[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
    int conn=true;
    F(i,0,n) conn = conn && vis[i];
    int even=true;
    F(i,0,n) even = even && (deg[i]%2==0);
    
    if(conn && even) cout<<"YES\n";
    else {
        cout<<"NO\n";
        cout<<deg<<"\n";
        printf("%d %d\n",conn,even);
        return 0;
    }
    int n_done=0;
    F(i,0,n){
        // exhaust paths from i to i
        // while(!graph[i].empty()){
            vi vis(n, -1);
            queue<int> q;
            q.push(i);
            int done=false;
            while(!q.empty() && !done){
                int u=q.front();q.pop();
                for(int v: graph[u]){
                    if(vis[v]==-1){
                        vis[v]=u;
                        if(v==i) {
                            done=true;
                            break;
                        }
                        q.push(v);
                    }
                }
            }
            if(!done) break;
            // direct edges
            int v=i,u=vis[i]; // u=parent
            cout<<vis<<"\n";
            while(u!=i){
                // remove u-v
                printf("%d %d\n",u+1,v+1);
                n_done++;
                graph[u].erase(v);
                graph[v].erase(u);
                int temp=v;
                v=vis[v];
                u=temp;
                
            }
            printf("\n");
        // }
    }
}


