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

vi dx={1,0,-1,0};
vi dy={0,1,0,-1};
int test(vvi &maze, int sx, int sy, vi diridx, string instr, int n, int m){
    int x=sx,y=sy;
    for(char c: instr){
        int ic=diridx[c-'0'];
        int ix=dx[ic],iy=dy[ic];
        //printf("%d %d %d %d\n",x,ix,y,iy);
        if(x+ix<0 || x+ix>=n || y+iy<0 || y+iy>=m) return 0;
        if(maze[x+ix][y+iy]==1) return 0;
        if(maze[x+ix][y+iy]==2) return 1;
        x=x+ix,y=y+iy;
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vvi maze(n,vi(m));
    int sx,sy;
    F(i,0,n){
        string s;
        cin>>s;
        F(j,0,m){
            maze[i][j]=0;
            if(s[j]=='E')
                maze[i][j]=2;
            else if(s[j]=='#')
                maze[i][j]=1;
            else if(s[j]=='S'){
                sx=i;
                sy=j;
            }
        }
    }
    string instr;
    cin>>instr;
    vi diridx={0,1,2,3};
    int count=0;
    do{
        //cout<<diridx<<"\n";
        count+=test(maze, sx, sy, diridx, instr, n, m);
    }while(next_permutation(all(diridx)));
    cout<<count<<"\n";
}


