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
    int n,k;
    cin>>n>>k;
    vector<ll> c(n);
    ll sum=0;
    F(i,0,n){
        cin>>c[i];
        sum+=c[i];
    }
    ll cost=0;
    F(i,0,n-1) cost+=c[i]*c[i+1];
    cost+=c[n-1]*c[0];
    vi taken(n);
    ll takensum=0;
    F(i,0,k){
        int x;
        cin>>x;
        x--;
        taken[x]=1;
        takensum+=c[x];
        int curr=takensum;
        if(taken[(x-1+n)%n]) curr-=c[(x-1+n)%n];
        if(taken[(x+1+n)%n]) curr-=c[(x+1+n)%n];
        cost+=c[x]*(sum-curr-c[(x-1+n)%n]-c[(x+1+n)%n]);
    }
    cout<<cost;
}


