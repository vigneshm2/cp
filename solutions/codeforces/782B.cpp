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

int check(double t, int n, vi& x, vi& v){
    // return true if all can meet in time t
    
    // find min point acheivable by going north
    // find max point acheivable by going south
    // if north pt < south pt, not possible
    
    double np=LINF,sp=-LINF;
    F(i,0,n){
        np = min(np, x[i]+v[i]*t);
        sp = max(sp, x[i]-v[i]*t);
    }
    return np>=sp;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    
    int n;
    cin>>n;
    vi x(n);
    cin>>x;
    vi v(n);
    cin>>v;
    
    const double eps=1e-7;
    double l=eps,r=1e10;
    while(abs(r-l)>eps){
        double mid=(l+r)/2.0;
        if(check(mid,n,x,v)) r=mid;
        else  l=mid+eps;
    }
    
    printf("%.12lf",l);

    
}


