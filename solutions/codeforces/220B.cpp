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

const int block = 320;
struct interval{
    int l,r;
    int idx;
};
bool mos_cmp(interval i1, interval i2){
    if(i1.l/block != i2.l/block){
        return i1.l < i2.l;
    }
    return i1.r < i2.r;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,m;
    scanf("%d %d",&n,&m);

    vi a(n);
    F(i,0,n) scanf("%d",&(a[i]));

    vi a2(a);
    sort(all(a2));
    auto last = unique(all(a2));
    a2.erase(last, a2.end());

    vi pos(n); // pos[i] = position of a[i] in a2.
    F(i,0,n) pos[i] = lower_bound(all(a2), a[i]) - a2.begin();

    //cout<<a2<<"\n";

    vector<interval> qs(m);
    F(i,0,m) {
        int l,r;
        scanf("%d %d",&l,&r);
        qs[i].l = l-1;
        qs[i].r = r-1;
        qs[i].idx = i;
    }
    sort(all(qs), mos_cmp);

    vi cs(m);
    int oldl=0,oldr=0;

    vi counts(n);
    counts[pos[0]]++;
    int currc = (counts[pos[0]] == a[0]);
    F(i,0,m){
        int l=qs[i].l,r=qs[i].r;
        if(l > oldl){
            for(int i=oldl;i<l;i++){
                if(counts[pos[i]] == a[i]) currc--;
                counts[pos[i]]--;
                if(counts[pos[i]] == a[i]) currc++;
            }
        } else if(l < oldl){
            for(int i=l;i<oldl;i++){
                if(counts[pos[i]] == a[i]) currc--;
                counts[pos[i]]++;
                if(counts[pos[i]] == a[i]) currc++;
            }
        }
        if(r < oldr){
            for(int i=r+1;i<=oldr;i++){
                if(counts[pos[i]] == a[i]) currc--;
                counts[pos[i]]++;
                if(counts[pos[i]] == a[i]) currc++;
            }
        } else if(r > oldr){
            for(int i=oldr+1;i<=r;i++){
                if(counts[pos[i]] == a[i]) currc--;
                counts[pos[i]]++;
                if(counts[pos[i]] == a[i]) currc++;
            }
        }
        for(auto i: counts) cout<<i<<" "; cout<<"\n";
        oldl = l;
        oldr = r;
        cs[qs[i].idx] = currc;
    }

    F(i,0,m) printf("%d\n",cs[i]);
}


