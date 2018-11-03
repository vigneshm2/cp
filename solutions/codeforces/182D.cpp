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


int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int check(string s1, string s2, int x){
    for(int i=0; i<s1.size(); i++){
        if(s1[i]!=s1[i%x]) return 0;
    }
    for(int i=0; i<s2.size(); i++){
        if(s2[i]!=s1[i%x]) return 0;
    }
    return 1;
}
vi divs(int g){
    vi c;
    F(i,1,g+1) if(g%i==0) c.pb(i);
    return c;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    string s1,s2;
    cin>>s1>>s2;
    int g=gcd(s1.length(), s2.length());
    int c=0;
    vi ds=divs(g);
    //cout<<g<<"\n"<<ds<<"\n";
    for(int i: ds){
        if(check(s1, s2, i)) c++;
    }
    cout<<c<<"\n";
}


