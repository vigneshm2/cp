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
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 1000000000+10;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
const ll lmod = 1000000007l;
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
#define se second
#define fi first

vll shortest_paths(int src, vvii &graph, int n){
    vll d(n,LINF);
    d[src]=0;
    priority_queue<pll> pq; // (-cost, vertex)
    pq.push(mp(0,src));
    while(!pq.empty()){
        ii p=pq.top();pq.pop();
        // cout<<"got "<<p<<"\n";
        int u=p.se;
        for(ii vp: graph[u]){
            // d[v] = d[u] + e[u,v]
            int c=vp.se,v=vp.fi;
            if(d[v]>d[u]+c){
                d[v]=d[u]+c;
                pq.push(mp(-d[v],v));
            }
        }
    }
    return d;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n,k,x,m,s;
        cin>>n>>k>>x>>m>>s;
        vvii graph(n);
        F(i,0,m){
            int a,b,c;
            cin>>a>>b>>c;
            a--;b--;
            graph[a].pb(mp(b,c));
            graph[b].pb(mp(a,c));
        }
        // F(i,0,k){
        //     F(j,i+1,k){
        //         graph[i].pb(mp(j,x));
        //         graph[j].pb(mp(i,x));
        //     }
        // }
        // F(i,0,n) cout<<graph[i]<<"\n";
        cout<<shortest_paths(s-1,graph,n)<<"\n";
    }
}


