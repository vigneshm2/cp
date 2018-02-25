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
    vi c(n);
    cin>>c;

    map<int, set<int>> cols;
    F(i,0,m){
        int u,v;
        cin>>u>>v;
        u--;v--;
        if(c[u]!=c[v]){
            cols[c[u]].insert(c[v]);
            cols[c[v]].insert(c[u]);
        }
    }

    int maxv=-1,maxc=-1;
    for(auto it: cols){
        int curr = it.second.size();
        int col=it.first;
        //cout<<col<<" "<<curr<<"\n";
        if(maxv<curr){
            maxv=curr;
            maxc=col;
        } else if(maxv==curr){
            maxc=min(maxc, col);
        }
    }
    if(maxc==-1){
        cout<<*min_element(all(c))<<"\n";
    }
    else cout<<maxc<<"\n";

}


