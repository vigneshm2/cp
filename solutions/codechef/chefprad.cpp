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

int maxmat(vll& c, vll& d, ll x, int e){
    // c,d sorted
    int m = d.size();
    int di=0;
    int count=0;
    F(ci,0,c.size()){
        ll curr = c[ci] + x;
        while(di < m){
            if(curr + e  < d[di]) break;
            else if(curr -e > d[di]) di++;
            else {
                //printf("match %d(%d) to %d(%d)\n",ci,curr,di,d[di]);
                count++;
                di++;
                break;
            }
        }
    }
    return count;
}

int max_maxmat(vll& c, vll& d, ll e){
    set<ll> possx;
    for(ll ce: c){
        for(ll de: d){
            possx.insert(de+e-ce);
            possx.insert(de-e-ce);
        }
    }
    //cout<<possx<<"\n";
    int maxv=-1;
    for(ll x: possx){
        maxv = max(maxv, maxmat(c, d, x, e));
    }
    return maxv;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        ll m,n,e;
        cin>>n>>m>>e;
        vll c(n),d(m);
        cin>>c>>d;

        sort(all(c));
        sort(all(d));

        //cout<<c<<"\n"<<d<<"\n";

        cout<<max_maxmat(c,d,e)<<"\n";
        //cout<<maxmat(c,d,18,e)<<"\n";
    }
    
}


