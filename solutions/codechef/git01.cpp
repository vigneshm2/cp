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

ll score(vvi &g1, vvi &g2, int n, int m){
    // cost to make g1 into g2
    ll c=0;
    F(i,0,n) F(j,0,m) {
        int t = g1[i][j]-g2[i][j];
        if(t==1) c+=5;
        else if(t==-1) c+=3;
    }
    return c;
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
        vvi grid(n,vi(m)); //R=1, G=0
        F(i,0,n){
            string s;
            cin>>s;
            F(j,0,m) grid[i][j] = (s[j]=='R');
        }

        vvi g1(grid), g2(grid);
        F(i,0,n) F(j,0,m) {
            g1[i][j] = (i+j)%2;
            g2[i][j] = (i+j+1)%2;
        }


        cout<<min(score(grid,g1,n,m),score(grid,g2,n,m))<<"\n";
    }
}


