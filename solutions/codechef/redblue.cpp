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

int eval(double a, double b, double c, ii p, int col){
    return col*(a*p.first + b*p.second +c);
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        int N = n+m;
        vii pts(N);
        vi col(N);
        F(i,0,n) {
            cin>>pts[i].first<<pts[i].second;
            col[i]=1;
        }
        F(i,n,N) {
            cin>>pts[i].first<<pts[i].second;
            col[i]=-1;
        }

        F(i,0,N) F(j,i+1,N){
            ii p1=pts[i], p2=pts[j];
            // line ax+by+1=0 through p1,p2
            double a,b,c;
            double x1=p1.first, y1=p1.first;
            double x2=p2.first, y2=p2.first;
            if(x1*y2-x2*y1 == 0){
                a = 1.0;
                b = (x2-x1)/(y1-y2);
                c = 0.0;
            } else {
                c = 1.0;
                a = (y1-y2)/(x1*y2-x2*y1);
                a = (x2-x1)/(x1*y2-x2*y1);
            }
            int rc,bc;
            rc = eval(a,b,c,pts[0],col[0]);
            bc = rc-1;
            int nbad = 0;
            F(i,0,n){
                F(i,0,n)
            }
        }

        
    }
}

/*
 * ax1+by1+1=0
 * ax2+by2+1=0
 * a(x1-x2) + b(y1-y2) = 0
 * b = -(x1-x2)/(y1-y2) a
 * ax1 -ay1(x1-x2)/(y1-y2) + 1 =0
 * a(- x1y2 + y1x2) = -(y1-y2)
 * a = (y1-y2)/(x1y2 -x2y1)
 */

