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
#include <bits/stdc++.h>

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
    string s;
    cin>>s;
    int n = s.size();

    int n0=0, n1=0;
    for(char c: s) if(c=='0') n0++; else n1++;
    int k = n0-n1;
    if(k<=0){
        cout<<"-1";
    } else {
        vvi points(k);
        int ok=true;
        unordered_set<int> eset, oset;
        F(i,0,k) eset.insert(i);
        F(i,0,n){
            if(!ok) break;
            int c=s[i]-'0';
            if(c==0){
                if(eset.empty()){
                    ok=false;
                } else {
                    int idx = *eset.begin();
                    points[idx].push_back(i);
                    eset.erase(idx);
                    oset.insert(idx);
                }
            } else {
                if(oset.empty()){
                    ok=false;
                } else {
                    int idx = *oset.begin();
                    points[idx].push_back(i);
                    oset.erase(idx);
                    eset.insert(idx);
                }
            }
            /*
            F(j,0,k){
                if((points[j].size()%2==0) ^ (c==1)) {
                    points[j].pb(i+1);
                    got = true;
                    break;
                }
            }
            if(!got) ok=false;
            */
        }
        if(ok){
            cout<<k<<"\n";
            F(i,0,k) cout<<points[i].size()<<" "<<points[i]<<"\n";
        } else {
            cout<<"-1";
        }
    }
}


