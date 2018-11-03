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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int INF = 1000000000;
const ll LINF = 1e18+10;
const double PI =3.141592653589793238;
const int mod=1000000007;
const double eps = 0.000001;
#pragma unused(INF,LINF,PI,mod,eps)

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

vvi find_subarrays(vvi a, int dir){
    int n=a.size(),m=a[0].size();
    vvi sub(n,vi(m));
    if(dir==0){
        // north
        F(i,0,m) sub[n-1][i] = a[n-1][i];
        for(int i=n-2;i>=0;i--) F(j,0,m) sub[i][j] = min(sub[i+1][j],0ll) + a[i][j];
    } else if(dir==1){
        //south
        F(i,0,m) sub[0][i] = a[0][i];
        for(int i=1;i<n;i++) F(j,0,m) sub[i][j] = min(sub[i-1][j],0ll) + a[i][j];
    } else if(dir==2){
        // east
        F(i,0,n) sub[i][m-1] = a[i][m-1];
        for(int j=m-2;j>=0;j--) F(i,0,n) sub[i][j] = min(sub[i][j+1],0ll) + a[i][j];
    } else if(dir==3){
        // west
        F(i,0,n) sub[i][0] = a[i][0];
        for(int j=1;j<m;j++) F(i,0,n) sub[i][j] = min(sub[i][j-1],0ll) + a[i][j];
    }

    return sub;
}

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
        vvi grid(n, vi(m));
        F(i,0,n) cin>>grid[i];
        vvi sN=find_subarrays(grid, 0);
        vvi sS=find_subarrays(grid, 1);
        vvi sE=find_subarrays(grid, 2);
        vvi sW=find_subarrays(grid, 3);
        
        ll mincost=LINF;
        F(i,0,n) F(j,0,m){
            ll cost = sN[i][j];
            cost += sS[i][j];
            cost += sE[i][j];
            cost += sW[i][j];
            cost -= 3ll*grid[i][j];
            mincost = min(cost, mincost);
        }
        cout<<mincost<<"\n";
    }
}
