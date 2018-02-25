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

ll count_in(ll diff){
    if(diff<2) return 0;
    // 2-1,  3-3, 4-6 5-10
    return (diff*(diff-1))/2;
}
ll count(string &s, ii p){
    int st = p.first, en=p.second;
    int n = s.size();
    ll  cnt=0;
    if(st>0 && en < n){
        if(s[st-1]==s[en]) cnt++;
    }
    return cnt+count_in(en-st);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    string s;
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        vii rng;
        ii currp; char currc=0;
        int idx;
        int n = s.size();
        F(i,0,n){
            if(currc == s[i]){
                currp.second++;
            } else {
                if(currp.second !=0)
                    rng.pb(currp);
                currp = mp(i,i+1);
                currc = s[i];
            }
        }
        rng.pb(currp);
        ll cnt=0;
        for(ii p: rng) {
            cnt+=count(s, p);
        }
        cout<<cnt<<"\n";
    }

}


