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

ll move_cost(vi& a, int n){
    int count=0;
    ll cost=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]){
            cost += (n-1-count-i);
            count++;
        }
    }
    return cost;
}
ll switch_cost(vi& a, int n){
    int sofar=0;
    ll cost=0;
    F(i,0,n){
        if(a[i]){
            if(i>0 && a[i-1]==0){
                cost += sofar;
            }
            sofar++;
        }
    }
    if(!a[n-1]) cost += sofar;
    return cost;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        vi c(n);
        F(i,0,n) c[i]=(s[i]=='1');
        cout<<move_cost(c,n) + switch_cost(c,n) <<"\n";
    }
}


