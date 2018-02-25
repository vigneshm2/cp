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
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vvi graph(n,vi(n,1));
        F(i,0,m){
            int a,b;
            cin>>a>>b;
            a--;b--;
            graph[a][b]=graph[b][a]=0;
        }
        F(i,0,n) graph[i][i]=0;
        vi visited(n);
        queue<int> q;
        int is_bip=1;
        F(i,0,n) if(!visited[i]){
            // cout<<"dfs on "<<i<<"\n";
            if(!is_bip) break;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                if(!is_bip) break;
                int u=q.front();q.pop();
                F(i,0,n){
                    if(graph[u][i]){
                        if(!visited[i]) {
                            visited[i]=3-visited[u];q.push(i);
                        } else {
                            if(visited[i]==visited[u]) {
                                // cout<<"conflict "<<i<<" "<<u<<"\n";
                                is_bip=0;
                            }
                        }
                    }
                }
            }
        }
        // cout<<visited<<"\n";
        if(is_bip) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}


