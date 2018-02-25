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

int checksnake(int st, int idx, vvi& sn, int got, int en=0){
    // st is leaving position of previous idx
    //printf("st %d idx %d got %d en %d\n", st, idx, got, en);
    if(idx==sn[0].size()) return true;
    if(en){
        // ended
        if(sn[0][idx] || sn[1][idx]) return false;
        return checksnake(st, idx+1, sn, 1, 1);
    }
    if(!sn[0][idx] && !sn[1][idx]) {
        if(!got) return checksnake(st, idx+1, sn, 0, 0);
        else return checksnake(st, idx+1, sn, 1, 1);
    }
    if(!sn[st][idx]) return false;
    if(!sn[1-st][idx]){
        // only st
        return checksnake(st, idx+1, sn, 1, 0);
    } else {
        // switch
        return checksnake(1-st, idx+1, sn, 1, 0);
    }
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        vvi sn(2,vi(n));
        F(i,0,n) sn[0][i] = a[i]=='#';
        F(i,0,n) sn[1][i] = b[i]=='#';

        //cout<<sn[0]<<"\n"<<sn[1]<<"\n";
        int ok=false;
        if(sn[0][0]) ok = ok || checksnake(0,1,sn,1);
        if(sn[1][0]) ok = ok || checksnake(1,1,sn,1);
        if(!sn[0][0] && !sn[1][0]) {
            ok = ok || checksnake(1, 1, sn, 0);
            ok = ok || checksnake(0, 1, sn, 0);
        }
        

        if(ok) cout<<"yes\n";
        else cout<<"no\n";
    }
}


