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

typedef vector<ll> vll;
typedef pair<ll,ll> pll;

pll range(ll a, ll b){
    return pll(abs(b-a)+1,a+b-1);
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n;ll l,r;
    cin>>n>>l>>r;
    vll vals(n);
    cin>>vals;
    sort(all(vals));
    vector<pll> ranges;
    F(i,0,n-1){
        pll rn = range(vals[i+1],vals[i]);
        rn.first=max(rn.first, l);
        rn.second = min(rn.second, r);
        if(rn.first<=rn.second)
            ranges.pb(rn);
    }
    // cout<<ranges<<"\n";
    sort(all(ranges));
    
    ll count=0,cur_end=-1;
    for(pll rn: ranges){
        if(rn.first>cur_end){
            // disjoint
            // printf("[%lld %lld]\n",rn.first, rn.second);
            count+=rn.second-rn.first+1;
            cur_end=rn.second;
        } else if(rn.second>cur_end){
            // start from cur_end
            // printf("(%lld %lld]\n",cur_end, rn.second);
            count+=rn.second-cur_end;
            cur_end=rn.second;
        } else {
            // ignore, rn.second<=cur_end
            ;
        }
    }
    cout<<count<<"\n";
}


