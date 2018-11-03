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

double f(int r,int b,int cr){
    int cb = r+b-cr;
    // double pr = ((double)r)/(r+b);
    // if(r+b==0) return 0;
    // if(r<0 || b<0 || cr<0 || cb<0) return 0;
    // double v=0;
    // if(cr>0) {
    //     v= max(v,pr*(f(r-1,b,cr-1)+1)+(1-pr)*f(r,b-1,cr-1));
    // }
    // if(cb>0){
    //     v= max(v,pr*f(r-1,b,cr)+(1-pr)*(f(r,b-1,cr)+1));
    // }
    // printf("f(%d,%d,%d,%d)=%lf\n",r,b,cr,r+b-cr,v);
    double v=r*(double)cr;
    v += b*(double)cb;
    v = v/(double)(r+b);
    return v;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int r,b,p;
        cin>>r>>b>>p;
        // cout<<f(r,b,p)<<"\n";
        printf("%.12f\n",f(r,b,p));
    }
}


