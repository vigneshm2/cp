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
template<typename T> ostream& operator<<(ostream &s,vector<vector<T>> t){
    for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?"\n":"");return s; }
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
    int n;
    cin>>n;
    
    vvi grid(n,vi(n));
    F(i,0,n){
        string s;
        cin>>s;
        F(j,0,n){
            grid[i][j] = (s[j]=='#');
        }
    }
    
    int dy[] = {0,0,-1,0,1};
    int dx[] = {0,1,1,2,1};
    int ok=true;
    F(i,0,n){
        F(j,0,n){
            if(!ok) break;
            if(grid[i][j]){
                if(j==0 || j==n-1 || i==n-2 || i==n-1) ok=false;
                else F(k,0,5){
                    if(!grid[i+dx[k]][j+dy[k]]) ok=false;
                    else grid[i+dx[k]][j+dy[k]]=0;
                }
                // cout<<grid<<"\n\n";
            }
        }
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}


