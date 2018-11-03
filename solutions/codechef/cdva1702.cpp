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

ll intexp(ll a, int e){
    if(e==0) return 1ll;
    if(e%2==0) return intexp(a*a,e/2);
    else return a*intexp(a*a,e/2);
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1) {
            cout<<"1\n2\n";
            continue;
        }
        ll sum=0;
        // exp 1
        sum+=(n+1);
        int cnt=1;
        for(int e=2;e<=65; e++){
            ll x = floor(pow(n,1.0/e));
            if(intexp(x,e) == n) sum+=(x+e),cnt++;
            else if(intexp(x+1,e) == n) sum+=(x+1+e),cnt++;
            else if(intexp(x-1,e) == n) sum+=(x-1+e),cnt++;
        }
        cout<<cnt<<"\n"<<sum<<"\n";
    }
}


