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
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
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

template<typename T>
void update(int idx, int value, vector<T> &t){
    // increment t[idx] by value
    while(idx < t.size()){
        t[idx] = (t[idx] + value) % mod;
        idx |= (idx+1);
    }
}

template<typename T>
T query(int idx, vector<T> &t){
    // get sum of t[0]..t[idx]
    T res=0;
    while(idx >= 0){
        res = (res + t[idx])%mod;
        idx = (idx & (idx+1))-1;
    }
    return res;
}

template<typename T>
T query_idx(int idx, vector<T> &t){
    // get t[idx]
    return query(idx,t) - (idx>0?query(idx-1,t):0);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    vi a(n);
    cin>>a;

    ld divsum = 0;
    F(i,0,n){
        divsum += (2ll*i-n+1)*((ld)a[i]);
    }

    ld onesum = 0;
    //F(i,0,n){
        //F(j,i+1,n){
            //if(a[j] == a[i]-1) onesum++;
            //else if(a[j]==a[i]+1) onesum--;
        //}
    //}
    //
    unordered_map<int, int> counts;
    F(i,0,n){
        counts[a[i]]++;
        onesum = onesum + (ll)counts[a[i]+1] - (ll)counts[a[i]-1];
    }



    
    printf("%.0Lf\n",onesum+divsum);
}


