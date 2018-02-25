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

int isprime(int n){
    ll i=2;
    for(i=2;i*i<=n; i++){
        if(n%i==0 && i<n) return 0;
    }
    cout<<"checked till "<<i<<"\n";
    return 1;
}
int cd[100];
int compute(int n){
    if(n<100 && cd[n]!=-1) return cd[n];
    if(isprime(n)) return 1;
    int minv=n;
    F(i,2,100){
        if(n-i<2) return minv;
        if(isprime(n-i)) {
            minv=min(minv, 1+compute(i));
            if(n>1000000) cout<<n-i<<" "<<i<<" "<<compute(i)<<"\n";
        }
    }
    if(n<100) cd[n]=minv;
    return minv;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    F(i,0,100) cd[i]=-1;
    int n;
    cin>>n;
    cout<<compute(n);
}


