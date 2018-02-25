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
typedef pair<int,int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int INF = 1000000000;
const ll LINF = 2e18+10;
const double PI =3.141592653589793238;
const int mod=1000000007;
const double eps = 0.000001;
#pragma unused(INF,LINF,PI,mod,eps)

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

ll diff(ll b,ll d,ll s,ll mb,ll md,ll ms){
    ll df = 0;
    df += (b>mb)?LINF:mb-b;
    df += (d>md)?LINF:md-d;
    df += (s>ms)?LINF:ms-s;
    // cout<<df<<"\n";
    return df;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    ll b,d,s;
    cin>>b>>d>>s;
    ll mindays = max(b,max(d,s));
    // estimate bb enter,bb exit - m,m,m
    // estimate bb enter,bd exit - m,m-1,m-1
    // estimate bb enter,bs exit - m,m,m-1
    // estimate bd,bb - m-1,m,m
    // estimate bd,bd - m,m,m
    // estimate bd,bs - m-1,m,m-1
    // bs,bb - m-1,m-1,m
    // bs,bd - m,m-1,m
    // bs,bs - m,m,m
    int db[] = {0,-1,-1,-1,0,0,0};
    int dd[] = {0,0,-1,0,-1,-1,0};
    int ds[] = {0,0,0,-1,0,-1,-1};
    int dn = 7;
    ll df=LINF;
    F(i,0,dn){
        df = min(df,diff(s,b,d,mindays+db[i],mindays+dd[i],mindays+ds[i]));
    }
    cout<<df<<"\n";
}
