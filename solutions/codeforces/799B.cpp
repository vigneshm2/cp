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
    int n;
    cin>>n;
    vi p(n);
    cin>>p;
    vi a(n),b(n);
    cin>>a>>b;
    
    vector<set<ii>> sets(3);
    F(i,0,n){
        sets[a[i]-1].insert(mp(p[i],i));
        sets[b[i]-1].insert(mp(p[i],i));
    }
    vi taken(n);

    int m;
    cin>>m;
    F(i,0,m){
        int c;
        cin>>c;
        //cout<<sets[c-1]<<"\n";
        while(!sets[c-1].empty()){
            auto top = sets[c-1].begin();
            if(taken[top->second]){
                sets[c-1].erase(top);
            } else {
                break;
            }
        }
        //cout<<sets[c-1]<<"\n";
        if(sets[c-1].empty())
            cout<<"-1 ";
        else {
            auto top = sets[c-1].begin();
            cout<<top->first<<" ";
            taken[top->second] = 1;
        }
    }

}


