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

const int INF = 1000000010;
const ll LINF = 1e17;
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
      vi a(n);
      cin>>a;
      vi diffs(n-1);
      F(i,0,n-1) diffs[i] = a[i+1] - a[i];
      if(n==2){
        cout<<min(a[0],a[1])<<"\n";
      } else if(n<10){
        int minv = INF;
        //rem removed
        F(rem,0,n){
          int d = a[1]-a[0],error=0;
          if(rem==0) d = a[2]-a[1];
          // cout<<"rem "<<rem<<"\n";
          F(i,0,n-1){
            int cd = a[i+1]-a[i];
            if(i==rem-1) continue;
            if(rem > 0 && i==rem) cd = a[i+1]-a[i-1];
            if(cd!=d) {
              error=1;
              // cout<<"error at "<<i<<"\n";
            }
          }
          if(!error) minv=min(minv,a[rem]);
        }
        if(minv<INF) cout<<minv<<"\n";
        else cout<<"-1\n";
      } else {
        int nd=INF;
        int minv = INF;
        F(i,0,n-3) if(diffs[i]==diffs[i+1] && diffs[i+1]==diffs[i+2]) nd=diffs[i];
        // cout<<diffs<<"\n";
        // cout<<nd<<"\n";
        vi prem;
        F(i,0,n-1) if(diffs[i]!=nd) prem.pb(i);
        if(prem.size()>10) {
          cout<<"-1\n";
          continue;
        }
        // cout<<prem<<"\n";
        F(i,0,prem.size()){
          int rem=prem[i];
          int d = a[1]-a[0],error=0;
          if(rem==0) d = a[2]-a[1];
          // cout<<"rem "<<rem<<"\n";
          F(i,0,n-1){
            int cd = a[i+1]-a[i];
            if(i==rem-1) continue;
            if(rem > 0 && i==rem) cd = a[i+1]-a[i-1];
            if(cd!=d) {
              error=1;
              // cout<<"error at "<<i<<"\n";
            }
          }
          if(!error) minv=min(minv,a[rem]);
        }
        if(minv<INF) cout<<minv<<"\n";
        else cout<<"-1\n";
      }
    }
}
