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

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    /*
     * arc angle = t -> acb angle = pi - t/2
     * same side : acb obtuse -> pi - t/2 > pi/2 -> t < pi -> 1/2 th
     * opp side : t/2 > pi/2 -> t > pi
     */
    int t;
    cin>>t;
    while(t--){
        int k,a,b;
        cin>>k>>a>>b;
        if(b<a) swap(a,b);
        // b>a
        int arc1 = b-a, arc2 = k-b+a;
        //printf("%d %d\n", arc1, arc2);
        int s_arc = min(arc1, arc2);
        int o_arc = max(arc1, arc2);

        int count = 0;
        if(2*s_arc < k) // s_arc < k/2
            count += s_arc - 1;
        if(2*s_arc > k)
            count += o_arc - 1;

        cout<<count<<"\n";
    }
}


