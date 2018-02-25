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

const int INF = 1000000000;
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

vvi graph;
vi visited;
vi subtree_count;
vll subtree_dsum;
vll subtree_allsum;

int dfs(int u){
    visited[u]=1;
    subtree_count[u]=1;
    ll c_sum=0,c_sq_sum=0;
    ll cs_sum=0,s_sum=0;
    ll deg=0;
    for(int v: graph[u]){
        if(!visited[v]){
            deg++;
            dfs(v);
            subtree_count[u]+=subtree_count[v];
            ll c = subtree_count[v];
            ll s = subtree_dsum[v];
            c_sum+=c;
            c_sq_sum+=c*c;
            cs_sum+=c*s;
            s_sum+=s;
        }
    }
    
    if(deg==0) subtree_dsum[u] = 0;
    else subtree_dsum[u] = c_sum+s_sum;
    subtree_allsum[u] = c_sum*s_sum - cs_sum + c_sum*c_sum - c_sq_sum;
    subtree_allsum[u] += subtree_dsum[u];
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,k;
    cin>>n>>k;
    
    graph=vvi(n);
    visited=vi(n);
    subtree_count = vi(n);
    subtree_dsum = vll(n);
    subtree_allsum = vll(n);
    
    F(i,0,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    dfs(0);
    
    cout<<subtree_count<<"\n";
    cout<<subtree_dsum<<"\n";
    cout<<subtree_allsum<<"\n";
}


