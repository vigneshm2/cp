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
    ll n,k;
    cin>>n>>k;
    vector<ll> l;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            l.pb(i);
        }
    }
    // cout<<l<<"\n";
    ll len=l.size();
    if(k<=len)
        cout<<l[k-1]<<"\n";
    else{
        // check sq
        ll last=l[l.size()-1];
        if(last*last==n){
            // cout<<2*len-1-k<<"\n";
            //1 2 3 4 6  9 12 18 36
            if(2*len-1-k>=0)
                cout<<n/l[2*len-1-k]<<"\n";
            else
                cout<<"-1\n";
        } else {
            //1 2 3 4 6 8 12 24
            if(2*len-k>=0)
                cout<<n/l[2*len-k]<<"\n";
            else
                cout<<"-1\n";
        }
    }
}


