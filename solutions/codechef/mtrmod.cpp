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

    int n,q;
    cin>>n>>q;
    vi a(n);
    vvi b(n,vi(n));
    F(i,0,n) cin>>b[i]; // ignore
    int min_nz=1;
    F(i,0,n) if(b[0][i]!=0) {min_nz=i; break;}
    F(i,0,n){
        if(i<min_nz) a[i]=0;
        else if(i==min_nz) a[i]=-b[0][i];
        else {
            // |a1-ai| = b[1][i]
            if(b[0][i] + b[0][min_nz] == b[min_nz][i])
                a[i]=b[0][i];
            else
                a[i]=-b[0][i];
        }
    }
    cout<<a<<"\n";
    F(i,0,q){
        int p;
        cin>>p;
        p--;
        vi c(n);
        cin>>c;

        // for i b[i][p]  = c[i]
        F(i,0,n) b[i][p] = b[p][i] = c[i];

    F(i,0,n) if(b[0][i]!=0) {min_nz=i; break;}
    F(i,0,n){
        if(i<min_nz) a[i]=0;
        else if(i==min_nz) a[i]=-b[0][i];
        else {
            // |a1-ai| = b[1][i]
            if(b[0][i] + b[0][min_nz] == b[min_nz][i])
                a[i]=b[0][i];
            else
                a[i]=-b[0][i];
        }
    }
        cout<<a<<"\n";

    }
}


