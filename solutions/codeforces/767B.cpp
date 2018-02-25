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
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 1000000000;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
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

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    ll ts,tf,t;
    cin>>ts>>tf>>t;
    int n;
    cin>>n;
    vll a(n);
    cin>>a;
    
    queue<pll> q; // (person, intime)
    vll times(2*n); // for personin, personout
    vi qsize(2*n);
    ll ct = a[0],idx=0;
    F(i,0,n){
        if(!q.empty() && q.front().second + t <=a[i]){
            // personout first
            ll tout = q.front().second + t;
            q.pop();
            times[idx]=tout;
            qsize[idx] = q.size();
            idx++;
        }
        q.push(mp(i,a[i]));
        times[idx]=a[i];
        qsize[idx] = q.size();
        idx++;
    }
    while(!q.empty()){
        // personout first
        ll tout = q.front().second + t;
        q.pop();
        times[idx]=tout;
        qsize[idx] = q.size();
        idx++;
    }
    cout<<times<<"\n";
    cout<<qsize<<"\n";
}


