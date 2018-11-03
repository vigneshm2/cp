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
    int n;
    cin>>n;
    vvi adj(n,vi(n));
    cin>>adj;

    vi vs(n);
    cin>>vs;
    //F(i,0,n) cout<<adj[i]<<"\n";
    reverse(all(vs));
    F(i,0,n) vs[i]--;
    //cout<<vs<<"\n";

    vvi sps(adj);
    vll sums(n);
    F(idx,0,n){
        ll spsum=0;
        int currv=vs[idx];
        F(u,0,n) F(v,0,n) {
            sps[u][v]=min(sps[u][v], sps[u][currv]+sps[currv][v]);
        }
        F(i,0,idx+1) F(j,0,idx+1) spsum+=sps[vs[i]][vs[j]];

        sums[idx]=(spsum);
        //cout<<"sps "<<idx<<"\n";
        //F(i,0,n) cout<<sps[i]<<"\n";
    }
    reverse(all(sums));
    cout<<sums<<"\n";
}


