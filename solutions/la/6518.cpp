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
typedef vector<vll> vvll;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 1000000000;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
const ll lmod = 1000000007l;
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

vvll matprod(vvll a, vvll b){
    int n=a.size(),m=a[0].size(),p=b[0].size();
    vvll c(n,vll(p));
    F(i,0,n) F(j,0,p) F(k,0,m) c[i][j] += a[i][k]*b[k][j];
    return c;
}
vvll matpow(vvll a, int n){
    //n>0
    if(n==1) return a;
    if(n%2==0) return matpow(matprod(a,a),n/2);
    else return matprod(a,matpow(a,n-1));
}
// x_i = f . x_{i-1}
vvll _x3(){
    vvll v = {{4},{2},{1},{1}};
    return v;
}
vvll _f(){
    vvll v = {{1,1,1,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
    return v;
}
vvll _xi(int i){
    // i>4
    return matprod(matpow(_f(),i-3),_x3());
}
ll tribble(int n){
    if(n<4){
        return _x3()[3-n][0];
    } else {
        return _xi(n)[0][0];
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
        int n;
        cin>>n;
        cout<<tribble(n)<<"\n";
    }
}


