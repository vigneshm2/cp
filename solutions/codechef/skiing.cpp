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
#pragma unused(INF, LINF, PI, lmod, mod, eps)

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

int nc=1;
void dfs1(int i, int j,int col ,vvi &grid, vvi &cols, int n, int m){
    cols[i][j]=col;
    if(i<n-1 && grid[i+1][j]==grid[i][j] && cols[i+1][j]==0) dfs1(i+1,j,col,grid,cols,n,m);
    if(j<m-1 && grid[i][j+1]==grid[i][j] && cols[i][j+1]==0) dfs1(i,j+1,col,grid,cols,n,m);
    if(i>0 && grid[i-1][j]==grid[i][j] && cols[i-1][j]==0) dfs1(i-1,j,col,grid,cols,n,m);
    if(j>0 && grid[i][j-1]==grid[i][j] && cols[i][j-1]==0) dfs1(i,j-1,col,grid,cols,n,m);
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        nc = 1;
        int n,m;
        cin>>n>>m;
        vvi grid(n,vi(m));
        F(i,0,n) cin>>grid[i];
        
        vvi cols(n, vi(m));
        F(i,0,n) F(j,0,m) if(cols[i][j]==0) dfs1(i,j,nc++,grid,cols,n,m);

        //F(i,0,n) cout<<cols[i]<<"\n";

        //cout<<nc<<"\n";
        
        vi ind(nc);
        F(i,0,n) F(j,0,m){
            if(i>0 && grid[i-1][j]>grid[i][j]) ind[cols[i][j]]++;
            if(j>0 && grid[i][j-1]>grid[i][j]) ind[cols[i][j]]++;
            if(i<n-1 && grid[i+1][j]>grid[i][j]) ind[cols[i][j]]++;
            if(j<m-1 && grid[i][j+1]>grid[i][j]) ind[cols[i][j]]++;
        }

        int cnt=0;
        F(i,1,nc){
            if(ind[i]==0) cnt++;
        }
       // cout<<ind<<"\n";
        cout<<cnt<<"\n";
        
    }
}


