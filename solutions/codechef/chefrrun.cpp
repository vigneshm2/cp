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

void dfs(int u, vi &next, vi &dfs_order, vi &visited){
    visited[u]=1;
    int v=next[u];
    if(!visited[v]) dfs(v, next, dfs_order, visited);
    dfs_order.pb(u);
}
void assign(int u, vvi &prev, vi &comps, int compid){
    comps[u] = compid;
    for(int v: prev[u]){
        if(!comps[v]) assign(v, prev, comps, compid);
    }
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d", &n);
        vi a(n);
        F(i,0,n) scanf("%d", &(a[i]));
        
        vi next(n);
        vvi prev(n,vi());
        F(i,0,n){
            int s=(i+a[i]+1)%n;
            next[i]=s;
            prev[s].pb(i);
        }
        
        vi dfs_order, visited(n);
        F(i,0,n) if(!visited[i]) dfs(i, next, dfs_order, visited);
        reverse(all(dfs_order));

        vi comps(n);
        int compid=1;
        for(int u: dfs_order){
            if(!comps[u]) assign(u, prev, comps, compid++);
        }
        vi compcount(compid), root(compid);
        int tot=0;
        F(i,0,n) compcount[comps[i]]++, root[comps[i]]=i;;
        F(i,0,compid){
            if(compcount[i]==1) tot+=(next[root[i]]==root[i]);
            else tot+=compcount[i];
        }
        cout<<tot<<"\n";
    }
}


