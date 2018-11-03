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
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int INF = 1000000000;
const ll LINF = 1e18+10;
const double PI =3.141592653589793238;
const int mod=1000000007;
const double eps = 0.000001;
#pragma unused(INF,LINF,PI,mod,eps)

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
    // freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    vi a(n);
    cin>>a;
    const int maxn=200010;
    int count[maxn];
    memset(count, 0, sizeof count);
    F(i,0,n) count[a[i]]++;
    vi distinct;
    F(i,0,maxn) if(count[i]) distinct.pb(i);
    int countsum[maxn];
    memset(countsum, 0, sizeof countsum);
    F(i,1,maxn) countsum[i] = countsum[i-1] + count[i];

    ll maxpow=-INF;
    for(int i: distinct){
        ll pow=0;
        // printf("i %d\n",i);
        for(ll val=1;val<=(maxn)/i;val++){
            int top = countsum[maxn-1];
            if((val+1)*i-1<maxn) top = countsum[(val+1)*i-1];
            int valn= top - countsum[val*i - 1];
            // if(valn!=0)
                // printf("val %d valn %d\n",val,valn);
            pow += i*val*valn;
        }
        maxpow = max(maxpow,pow);
    }

    cout<<maxpow<<"\n";
}
