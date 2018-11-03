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

void dfs(int u, vvi &graph, vi &comp, int compno){
    comp[u]=compno;
    for(int v:graph[u]){
        if(comp[v]<0) dfs(v,graph,comp,compno);
    }
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,m,k;
    cin>>n>>m>>k;
    vi c(n);
    cin>>c;
    vvi graph(n,vi());
    F(i,0,m){
        int l,r;
        cin>>l>>r;
        l--;r--;
        graph[l].pb(r);
        graph[r].pb(l);
    }
    vi comp(n,-1);
    int compno=0;
    F(i,0,n) if(comp[i]<0) dfs(i,graph,comp,compno++);
    vvi compgrp(compno,vi());
    F(i,0,n) compgrp[comp[i]].pb(i);
    int changes=0;
    F(i,0,compno){
        map<int,int> freq;
        for(int v:compgrp[i]){
            freq[c[v]]++;
        }
        int maxc=max_element(freq.begin(),freq.end(),
            [](const ii &p1, const ii &p2) -> int {
                return p1.second < p2.second;
            })->first,ch=0;
        for(int v:compgrp[i])
            ch += (c[v]!=maxc);
        // cout<<i<<", "<<compgrp[i]<<", ";
        // for(int v:compgrp[i]) cout<<c[v]<<" ";
        // cout<<", "<<maxc<<", "<<ch<<"\n";
        changes+=ch;
    }
    cout<<changes<<"\n";
}
