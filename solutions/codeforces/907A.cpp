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

int check(vi v, vi c){
    return (v[0]<=c[0]) && (c[0]<=2*v[0]) &&
        (v[1]<=c[1]) && (c[1]<=2*v[1]) &&
        (v[2]<=c[2]) && (c[2]<=2*v[2]) &&
        (v[3]<=c[2]) && (c[0]>c[1]) && (c[1]>c[2]) &&
        (c[2]<=2*v[3]) && (c[1]>2*v[3]);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    vi v(4);
    cin>>v;
    vi c(3);
    int ok=0;
    F(i,0,110) F(j,i+1,110) F(k,j+1,110) {
        if(ok) break;
        if(check(v,{k,j,i})){
            ok=1;
            printf("%d\n%d\n%d\n",k,j,i);
        }
    }
    if(!ok) printf("-1\n");
}


