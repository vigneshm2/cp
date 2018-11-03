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
    int n;
    cin>>n;
    vector<ll> c(n);
    cin>>c;
    vector<string> strs(n);
    cin>>strs;
    vector<ll> norev(n,LINF),rev(n,LINF);
    norev[0]=c[0],rev[0]=0;
    F(i,1,n){
        if(strs[i]>=strs[i-1]) 
            rev[i]=min(rev[i],rev[i-1]);
        reverse(all(strs[i]));
        if(strs[i]>=strs[i-1]) // reverse(strs[i])>=strs[i-1]
            norev[i]=min(norev[i],rev[i-1]+c[i]);
        reverse(all(strs[i-1]));
        if(strs[i]>=strs[i-1]) // reverse(strs[i])>=reverse(strs[i-1])
            norev[i]=min(norev[i],norev[i-1]+c[i]);
        reverse(all(strs[i]));
        if(strs[i]>=strs[i-1]) // strs[i]>=reverse(strs[i-1])
            rev[i]=min(rev[i],norev[i-1]);
        reverse(all(strs[i-1]));
    }
    ll score = min(rev[n-1],norev[n-1]);
    if(score>=LINF) cout<<"-1\n";
    else cout<<score<<"\n";
}


