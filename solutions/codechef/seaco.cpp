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

struct cmd{
    int t;
    int l;
    int r;
};

template<typename T>
void update(int idx, ii value, vector<T> &t){
    // increment t[idx] by value
    while(idx < t.size()){
        t[idx].first = (t[idx].first + value.first) % mod;
        t[idx].second = (t[idx].second + value.second) % mod;
        idx |= (idx+1);
    }
}

void update_range(int left, int right,ll value, vector<pll> &t){
    update(left, mp(value, -value*(left-1)), t);
    update(right, mp(-value, value*right), t);
}

ll query(int idx, vector<pll> &t){
    // get sum of t[0]..t[idx]
    if(idx<0) return 0;
    ll  mul=0;
    ll add=0;
    ll start = idx;
    while(idx >= 0){
        mul = (mul+ t[idx].first)%mod;
        add = (add+ t[idx].second)%mod;
        idx = (idx & (idx+1))-1;
    }
    return (mul*start+add)%mod;
}

ll query_idx(int idx, vector<pll> &t){
    return query(idx,t) - query(idx-1,t);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        vector<cmd> cmds;
        F(i,0,m){
            int t,l,r;
            cin>>t>>l>>r;
            cmd c = {.t=t,.l=l-1,.r=r-1};
            cmds.pb(c);
        }

        vll ncalls(m); // finds how many times each cmd has been called
        vector<pll> ncalls_tree(m+1);
        for(int i=m-1;i>=0;i--){
            //ncalls[i]=(ncalls[i]+1)%mod;
            update_range(i,i,1,ncalls_tree);
            ncalls[i] = query_idx(i, ncalls_tree);
            cmd c = cmds[i];
            if(c.t == 2){
                int l=c.l,r=c.r+1;
                update_range(l,r, ncalls[i], ncalls_tree);
                //F(j,l,r){
                    //ncalls[j] = (ncalls[j] + ncalls[i])%mod;
                //}
            }
        }
        //cout<<"ncalls: "<<ncalls<<"\n";
        
        vll diffs(n+1); // to do range updates
        vll a(n);
        F(i,0,m){
            cmd c=cmds[i];
            if(c.t==1){
                diffs[c.l] = (diffs[c.l] + ncalls[i]) % mod;
                diffs[c.r+1] = (diffs[c.r+1] - ncalls[i] + mod) % mod;
            }
        }
        a[0] = diffs[0];
                //cout<<diffs<<"\n";
        F(i,1,n) a[i] = (diffs[i] + a[i-1])%mod;
        cout<<a<<"\n";
        
    }
}


