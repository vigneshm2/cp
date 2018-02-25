//
//  main.cpp
//  code
//
//  Created by Vignesh Manoharan
//

#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FF(i,L,R) for (int i = L-1; i >= R; i--)
#define get1(a) scanf("%d", &(a))
#define get2(a,b) scanf("%d%d", &a, &b)
#define get3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define si(n) int (n); scanf("%d",&(n))
#define sc(n) char (n); scanf(" %c",&(n))
#define si2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define si3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define TESTS wez(testow);while(testow--)
#define clr(a,x) memset(a,x,sizeof(a))
#define REMAX(a,b) (a)=max((a),(b))
#define REMIN(a,b) (a)=min((a),(b));
#define ALL(c) (c).begin(),(c).end()
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define PI 3.1415926535897931159979635
#define inf 100000
#define INF 1000001000
#define LINF 100000000000000000LL
#define EPS 1e-9
#define printa(arr,n) F(_idx_1,0,n) cout<<(arr)[_idx_1]<<" ";cout<<"\n";
#define printa2d(arr,l1,l2) F(_idx_1,0,l1) { F(_idx_2,0,l2) cout<<(arr)[_idx_1][_idx_2]<<" "; cout<<"\n";}
#define getvi(a,n) F(i,0,n){ wez(x); a.pb(x); }
#define geta(a,n) wez((n));vi (a)(n);F(i,0,(n)) get1((a)[i]);
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
// directions
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
#define FLL(i,L,R) for (ll i = L; i < R; i++)
#pragma unused(fx)
#pragma unused(fxx)
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,(t).size())s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }

vvi graph;
vi dfs_num,dfs_low,onstack;
stack<int> s;
vi scc;
int dfs_count=0,scc_count=0;
void dfs(int u){
    dfs_num[u]=dfs_low[u]=dfs_count++;
    onstack[u]=1;
    s.push(u);
    for(int v:graph[u]){
        if(dfs_num[v]==INF){
            dfs(v);
            dfs_low[u]=min(dfs_low[v],dfs_low[u]);
        } else {
            if(onstack[v]){
                dfs_low[u]=min(dfs_low[u],dfs_num[v]);
            }
        }
    }
    if(dfs_low[u]==dfs_num[u]){
        int v=-1;
        do{
            v=s.top();
            s.pop();
            onstack[v]=false;
            scc[v]=scc_count;
        }while(v!=u);
        scc_count++;
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/vigneshm/Documents/codespace/ios/code/input.txt","r",stdin);
    freopen("/Users/vigneshm/Documents/codespace/ios/code/output.txt","w",stdout);
#endif
    si(n);
    graph=vvi(n,vi());
    dfs_num=dfs_low=vi(n,INF);
    onstack=scc=vi(n);
    vi cost(n);
    F(i,0,n) get1(cost[i]);
    si(m);
    F(i,0,m){
        si2(a,b);
        graph[a-1].pb(b-1);
    }
    F(i,0,n){
        if(dfs_num[i]==INF) dfs(i);
    }
    vi min_cost(scc_count,INF);
    vi min_count(scc_count,0);
    F(i,0,n){
        if(min_cost[scc[i]]>cost[i]){
            min_cost[scc[i]]=cost[i];
            min_count[scc[i]]=1;
        } else if(min_cost[scc[i]]==cost[i]){
            min_count[scc[i]]++;
        }
    }
    ll cost_sum=0;
    F(i,0,scc_count) cost_sum+=min_cost[i];
    ll count_sum=1;
    F(i,0,scc_count) count_sum=(count_sum*min_count[i])%1000000007;
    cout<<cost_sum<<" "<<count_sum<<"\n";
}




