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
    int t;
    cin>>t;
    while(t--){
        int n1,n2;
        cin>>n1>>n2;
        int n=max(n1,n2);
        int m=n;
        vvi a(n+1, vi(n+1));
        F(i,1,n1+1) F(j,1,n2+1) cin>>a[i][j];
        F(i,n1+1,n+1) F(j,1,n+1) a[i][j]=0;
        F(i,0,n+1) F(j,n2+1,n+1) a[i][j]=0;

        vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
        for (int i=1; i<=n; ++i) {
            p[0] = i;
            int j0 = 0;
            vector<int> minv (m+1, INF);
            vector<char> used (m+1, false);
            do {
                used[j0] = true;
                int i0 = p[j0],  delta = INF,  j1;
                for (int j=1; j<=m; ++j)
                    if (!used[j]) {
                        int cur = a[i0][j]-u[i0]-v[j];
                        if (cur < minv[j])
                            minv[j] = cur,  way[j] = j0;
                        if (minv[j] < delta)
                            delta = minv[j],  j1 = j;
                    }
                for (int j=0; j<=m; ++j)
                    if (used[j])
                        u[p[j]] += delta,  v[j] -= delta;
                    else
                        minv[j] -= delta;
                j0 = j1;
            } while (p[j0] != 0);
            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0);
        }
        cout<<-v[0]<<"\n";
    }
}


