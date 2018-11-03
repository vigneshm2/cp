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
    int t;
    cin>>t;
    int dp[110][110][110];
    while(t--){
        F(i,0,110) F(j,0,110) F(k,0,110) dp[i][j][k]=0;
        int x,y,z;
        int a,b,c;
        cin>>x>>y>>z;
        cin>>a>>b>>c;
        F(i,0,x+1) F(j,0,y+1) F(k,0,z+1){
            int minc=INF;
            if(i>0) minc = min(minc, a+dp[i-1][j][k]);
            if(j>0) minc = min(minc, a+dp[i][j-1][k]);
            if(k>0) minc = min(minc, a+dp[i][j][k-1]);

            if(i>0 && j>0) minc = min(minc, b+dp[i-1][j-1][k]);
            if(k>0 && j>0) minc = min(minc, b+dp[i][j-1][k-1]);
            if(i>0 && k>0) minc = min(minc, b+dp[i-1][j][k-1]);

            if(i>0 && j>0 && k>0) minc = min(minc, c+dp[i-1][j-1][k-1]);
            dp[i][j][k] = minc;
            if(i==0 && j==0 && k==0) dp[i][j][k]=0;
        }
        cout<<dp[x][y][z]<<"\n";
    }
}


/*

    ad = a1 + b12 + b13 + c
    bd = a2 + b12 + b23 + c
    cd = a3 + b13 + b13 + c
    
    min A*(a1+a2+a3) + B*(b12 + b23 + b13) + C*c

    ai,bij,c > 0
*/
