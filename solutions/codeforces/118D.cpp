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
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;

    int mmod=100000000;
    int dp1[110][110][20], dp2[110][110][20];
    F(i,0,n1+1) F(j,0,n2+1) F(k,1,20) dp1[i][j][k] = dp2[i][j][k]=0;
    // dp[1s used][2s used][consecutive so far]
    
    F(i,0,n1+1) F(j,0,n2+1) F(k,1,20){
        if(i==0 && j==0 && k==1) {
            dp1[i][j][k]=dp2[i][j][k]=1;
            continue;
        }
        if(k > k1 || i==0) dp1[i][j][k] = 0;
        else {
            if(k>1){
                if(i>=k)
                    dp1[i][j][k] = dp1[i-1][j][k-1];
            }else 
                F(a,1,20) dp1[i][j][k] =(dp1[i][j][k] + dp2[i-1][j][a])%mmod;
        }
        if(k > k2 || j==0) dp2[i][j][k] = 0;
        else {
            if(k>1){
                if(j>=k)
                    dp2[i][j][k] = dp2[i][j-1][k-1];
            }else
                F(a,1,20) dp2[i][j][k] =(dp2[i][j][k] + dp1[i][j-1][a])%mmod;
        }
    }
    //F(i,0,n1+1) F(j,0,n2+1) F(k,1,4)
        //printf("%d %d %d 1-%d 2-%d\n",i,j,k,dp1[i][j][k],dp2[i][j][k]);
    int tot=0;
    F(k,1,20) tot=(tot+dp1[n1][n2][k]+dp2[n1][n2][k])%mmod;
    cout<<tot<<"\n";
}


