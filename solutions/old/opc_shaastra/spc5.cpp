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

const int N = 100010;
int bit_e[N], bit_o[N];

void update(int *bit, int idx,int val){
    while(idx<=N){
        bit[idx]+=val;
        idx+=(idx & -idx);
    }
}
int query(int *bit, int idx){
    int sum=0;
    if(idx==0) return 0;
    while(idx>0){
        sum+=bit[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int n;
vi dfs_order;
int dfs_count;
vi tree_size;
vvi graph;
vi height;

void dfs(int u){
    tree_size[u]=1;
    dfs_order[u]=dfs_count++;
    for(int v: graph[u]){
        if(dfs_order[v]==-1){
            height[v] = height[u]+1;
            dfs(v);
            tree_size[u]+=tree_size[v];
        }
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
        int o;
        cin>>o;
        vi types(o),xvs(o);
        F(i,0,o) cin>>types[i]>>xvs[i];
        
        n = 1;
        graph = vvi(1);
        vi ns(o);
        F(i,0,o){
            if(types[i]==0){
                // edge from n to xvs[i]
                graph.push_back(vi(1,xvs[i]));
                graph[xvs[i]].push_back(n);
                ns[i]=n;
                n++;
            }
        }
        dfs_order = vi(n,-1);
        tree_size = vi(n,0);
        height = vi(n,0);
        dfs_count=2;
        dfs(0);
        // cout<<height<<"\n";
        
        F(i,0,N) bit_e[i]=0;
        F(i,0,N) bit_o[i]=0;
        
        update(bit_e, dfs_order[0], 1);
        F(i,0,o){
            if(types[i]==0){
                if(height[ns[i]]%2==1){
                    update(bit_o, dfs_order[ns[i]], 1);
                } else {
                    update(bit_e, dfs_order[ns[i]], 1);
                }
            } else {
                int x = xvs[i];
                ll a = query(bit_o, dfs_order[x]+tree_size[x]-1) - query(bit_o, dfs_order[x]-1);
                ll b = query(bit_e, dfs_order[x]+tree_size[x]-1) - query(bit_e, dfs_order[x]-1);
                cout<<a<<" "<<b<<"\n";
                cout<<(a*(a-1))/2+(b*(b-1))/2<<"\n";
            }
        }
    }
}


