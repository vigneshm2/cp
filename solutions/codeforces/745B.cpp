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
    
    vvi grid(n,vi(m));
    ii topleft,botright;
    topleft=mp(0,0);
    botright=mp(-1,-1);
    int first=false;
    F(i,0,n) F(j,0,m) {
        char c;
        cin>>c;
        grid[i][j]=(c=='X');
        if(grid[i][j]){
            if(!first) {
                topleft=mp(i,j);
                first=true;
            }
            botright=mp(i,j);
        }
    }
    // cout<<topleft<<"\n"<<botright<<"\n";
    int filled=true;
    if(topleft.first>botright.first || topleft.second>botright.second)
        filled=false;
    // check if tl-br is filled
    for(int i=0; i<n; i++){
        if(!filled) break;
        for(int j=0; j<m; j++){
            int is_in = (topleft.first<=i) && (botright.first>=i) && \
                (topleft.second<=j) && (botright.second>=j);
            if(grid[i][j]!=is_in)
                filled=false;
        }
    }

    if(filled) cout<<"YES\n";
    else cout<<"NO\n";
}


