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

int check(vector<string> ss, int n, string t){
    //cout<<t<<"\n";
    vi count(26);
    F(i,0,n) count[t[i]-'a']++;
    int dup=0;
    F(i,0,26) if(count[i]>1) dup=1;
    for(string s: ss){
        int id1=-1,id2=-1,wc=0;
        F(i,0,n){
            if(s[i] != t[i]){
                wc++;
                if(id1!=-1) id2=i;
                else id1=i;
            }
        }
        int ok = (wc==0 && dup) || (wc==1 && dup && s[id1] == t[id2]) || (wc==2 && s[id1]==t[id2] && s[id2]==t[id1]);
        if(!ok) {
            //cout<<wc<<" "<<id1<<" "<<id2<<"\n";
            //cout<<t<<" not ok for "<<s<<"\n";
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int k,n;
    cin>>k>>n;
    vector<string> ss(k);
    cin>>ss;

    string t(ss[0]);
    int got=0;
    F(i,0,n) F(j,i+1,n){
        if(got) break;
        swap(t[i], t[j]);
        if(check(ss, n, t)){
            got=1;
            break;
        }
        swap(t[i],t[j]);
    }
    if(got)
        cout<<t<<"\n";
    else
        cout<<"-1\n";

}


