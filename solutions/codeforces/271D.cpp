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

struct subst{
    int st,len;
    ll hash;
};

ll P=111181111ll,Q=777767777ll;
ll P1=111191111ll,Q1=77777777ll;

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    string s,oks;
    int k;
    cin>>s>>oks>>k;

    int n=s.size();
    vi ok(26);
    F(i,0,n) ok[i]=(oks[i]=='1');
    vector<pair<ll,ll>> subs;
    int cnt=0;
    F(i,0,n){
        int count=0;
        ll hash=Q,hash1=Q1;
        F(j,i,n){
            // add s[i]
            char c=s[j]-'a';
            if(ok[c]==0) count++;
            //cout<<s.substr(i,j-i+1)<<" "<<count<<"\n";
            if(count>k) break;
            hash=(hash*P+c+Q);
            hash1=hash1*P1+c+Q1;
            cnt++;
            subs.pb(mp(hash,hash1));
        }
    }
    cout<<cnt<<"\n";
    /*
    set<string> subs_set;
    for(subst x: subs){
        //printf("%d,%d\n",x.st,x.en);
        cout<<s.substr(x.st,x.len)<<"\n";
        subs_set.insert(s.substr(x.st,x.len));

    }
    */
    sort(all(subs));
    //auto en=unique(all(subs));
    //cout<<distance(subs.begin(),en)<<"\n";
    //cout<<subs.size()<<"\n";
}


