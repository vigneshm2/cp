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
    for(int i=0;i<(t).size();i++)s<<(t)[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()

void offsets(vi a, vi b, int c){
    // find offsets for names[idx],names[idx+1]
    // k such that names[idx]<=names[idx+1]
    // find pos of difference
    int i=0;
    for(;i<a.size() && i<b.size() && a[i]==b[i];i++);
    if(i==a.size()) cout<<"all\n";
    else if(i==b.size()) cout<<"none\n";
    else {
        int ai=a[i],bi=b[i];
        cout<<(1-ai+c)%c<<" to "<<c-bi<<"\n";
    }
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    #endif
    int n,c;
    cin>>n>>c;
    vvi names(n);
    F(i,0,n){
        int l;
        cin>>l;
        names[i] = vi(l);
        F(j,0,l) cin>>names[i][j];
    }
    F(i,0,n) cout<<names[i]<<"\n";
    F(i,0,n-1){
        offsets(names[i], names[i+1], c);
    }
}
