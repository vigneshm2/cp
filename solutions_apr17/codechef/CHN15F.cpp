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
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
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

int w,h,m;

int nextpos(int pos, int lev, int next_lev){
    return (pos | (pos<<1) | (pos>>1)) & lev & next_lev;
}
int dp[(1<<7)+10][(1<<7)+10][110];
//compute(pos, lev, ht) = no of boards where pos - reachable positions, lev - current level, ht - current height
// pos,lev,ht -> (reachable from pos to nextlev),nextlev,ht+1
void compute(){
    // ht=1 => reachable = 1
    int nlev = 1<<w;
    F(pos,0,nlev) F(lev,0,nlev) dp[pos][lev][1] = (pos == 1);
    F(ht,1,h+1){
        F(lev,0,nlev){
            // pos is subset of lev
            for(int pos=lev; pos>0; pos = lev & (pos-1)){
                // add pos,lev,ht to nextlevs
                F(nextlev,0,nlev){
                    int npos = nextpos(pos, lev, nextlev);
                    // printf("updating %d,%d,%d with %d,%d,%d\n",npos,nextlev,ht+1,pos,lev,ht);
                    dp[npos][nextlev][ht+1] = (dp[npos][nextlev][ht+1] + dp[pos][lev][ht])%m;
                }
            }
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
        cin>>w>>h>>m;
        memset(dp, 0, sizeof(dp));
        int s=0;
        compute();
        // F(i,1,h+1) F(lev,0,1<<w) for(int pos=lev; pos > 0; pos=lev&(pos-1))
            // printf("pos %d,lev %d, ht %d = %d\n",pos,lev,i,dp[pos][lev][i]);
        F(lev,0,1<<w) for(int pos=lev; pos > 0; pos=lev&(pos-1)) s = (s + dp[pos][lev][h])%m;
        cout<<s<<"\n";
    }
}
