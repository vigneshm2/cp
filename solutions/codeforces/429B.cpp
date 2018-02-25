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

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;

    vvi w(n,vi(m));
    cin>>w;

    vvi dp1(n, vi(m)); // 1,1 to i,j
    vvi dp2(dp1),dp3(dp1),dp4(dp1);
    //2: n,1 to i,j
    //3: n,m to i,j
    //4: 1,m to i,j
    F(i,0,n) F(j,0,m){
        dp1[i][j]=w[i][j];
        if(i>0) dp1[i][j] = max(dp1[i][j],dp1[i-1][j]+w[i][j]);
        if(j>0) dp1[i][j] = max(dp1[i][j],dp1[i][j-1]+w[i][j]);
    }
    for(int i=n-1;i>=0;i--) F(j,0,m){
        dp2[i][j]=w[i][j];
        if(i<n-1) dp2[i][j] = max(dp2[i][j],dp2[i+1][j]+w[i][j]);
        if(j>0) dp2[i][j] = max(dp2[i][j],dp2[i][j-1]+w[i][j]);
    }
    for(int i=n-1;i>=0;i--) for(int j=m-1;j>=0;j--){
        dp3[i][j]=w[i][j];
        if(i<n-1) dp3[i][j] = max(dp3[i][j],dp3[i+1][j]+w[i][j]);
        if(j<m-1) dp3[i][j] = max(dp3[i][j],dp3[i][j+1]+w[i][j]);
    }
    F(i,0,n) for(int j=m-1;j>=0;j--){
        dp4[i][j]=w[i][j];
        if(i>0) dp4[i][j] = max(dp4[i][j],dp4[i-1][j]+w[i][j]);
        if(j<m-1) dp4[i][j] = max(dp4[i][j],dp4[i][j+1]+w[i][j]);
    }
    int maxv=0;
    F(i,1,n-1) F(j,1,m-1){
        maxv=max(maxv, dp1[i][j-1]+dp3[i][j+1]+dp2[i+1][j]+dp4[i-1][j]);
        maxv=max(maxv, dp1[i-1][j]+dp3[i+1][j]+dp2[i][j-1]+dp4[i][j+1]);
    }
    cout<<maxv<<"\n";
}


