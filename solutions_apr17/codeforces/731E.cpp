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
    freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    vi a(n);
    cin>>a;
    // score[i] = max(sum(a[..j])-score[j+1])  take j -> your score sum[..i] + sum(a[i..j]), opp score score[j+1] i<=j<=n-1
    // a=1,-5,-2,3
    // s=1,-4,-6,-3
    // score[4] = 0
    // score[3] = -3-0 = -3
    // score[2] =
    // score[1] = max() = 3             -6+3=-3
    // score[0] = max(1-3,-6-1,-8) = 7  1+3=4
    vector<ll> sums(n);
    sums[0]=a[0];F(i,1,n) sums[i]=sums[i-1]+a[i];
    ll score=sums[n-1];
    for(int i=n-2;i>=1;i--){
        ll newscore = sums[i] - score;
        score = max(newscore, score);
    }
    cout<<score<<"\n";
}
