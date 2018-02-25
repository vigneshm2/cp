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
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

#define width 5
#define height 5

int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,-1,-1,1};

vvi grid(width, vi(height));
vvi color(width, vi(height));
void dfs(int x, int y, int cc){
    color[x][y] = cc;
    F(i,0,8){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=width || ny>=height) continue;
        if(!color[nx][ny] && grid[nx][ny])
            dfs(nx,ny,cc);
    }
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    #endif
    string filename;
    cin>>filename;
    freopen(filename.c_str(), "r", stdin);
    string s;
    F(i,0,width){
        getline(cin, s);
        for(int j=0;j<(int)s.size();j++) grid[i][j] = (s[j]=='#');
    }
    
    int cc=1;
    F(i,0,width) F(j,0,height){
        if(grid[i][j] && !color[i][j]) dfs(i,j,cc++);
    }
    
    vi counts(cc);
    F(i,0,width) F(j,0,height){
        counts[color[i][j]]++;
    }
    F(i,1,cc){
        cout<<"Island "<<i<<": "<<counts[i]<<"\n";
    }
    cout<<"Number of continents "<<cc-1<<"\n";
    // F(i,0,width) cout<<grid[i]<<"\n";
    // F(i,0,width) cout<<color[i]<<"\n";
    // cout<<cc;
}


