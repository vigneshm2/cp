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

void xor_row(vi &a, vi &b, int n){
  // does b=b^a
  F(i,0,n) b[i]=b[i]^a[i];
}
vvi inverse_2(vvi a){
  int n = a.size();
  // a is nxn matrix with a[i][i]=1 for all i
  vvi b(n,vi(n));
  F(i,0,n) b[i][i]=1;
  F(i,0,n){
    // clear column i for j>i using a[i][i]
    int swp=-1;
    F(j,i,n) if(a[j][i]){
      swp=j;
      break;
    }
    if(swp==-1) {
      cout<<"error\n";
      F(i,0,n) cout<<a[i]<<"\n";
      cout<<"\n";
      return vvi();
    }
    if(swp!=i) {
      xor_row(a[swp],a[i],n);
      xor_row(b[swp],b[i],n);
    }
    if(swp!=i) printf("adding %d to %d\n",swp,i);
    F(j,i+1,n){
      if(a[j][i]){
        xor_row(a[i],a[j],n);
        xor_row(b[i],b[j],n);
      }
    }
  }
  cout<<"diagonalized\n";
  F(i,0,n) cout<<a[i]<<"\n";
  cout<<"\n";
  F(i,0,n){
    //clear non diagonal - a[i][j] j>i
    F(j,i+1,n){
      if(a[i][j]) {
        xor_row(a[j],a[i],n);
        xor_row(b[j],b[i],n);
      }
    }
  }
  cout<<"unitary\n";
  F(i,0,n) cout<<a[i]<<"\n";
  cout<<"\n";
  return b;
}

vvi adj_mat(int n){
  // creates the n^2xn^2 matrix
  int dx[5] = {0,0,0,1,-1};
  int dy[5] = {0,1,-1,0,0};
  int ns=n*n;
  vvi a(ns,vi(ns));
  F(sq,0,ns){
    int r=sq/n,c=sq%n;
    F(i,0,5){
      int r2=r+dx[i],c2=c+dy[i];
      if(r2>=0 && c2>=0 && r2<n && c2<n)
        a[sq][r2*n+c2]=1;
    }
  }
  return a;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int x;
    cin>>x;
    vvi a = adj_mat(x);
    F(i,0,a.size()) cout<<a[i]<<"\n";
    cout<<"\n";
    vvi b = inverse_2(a);
    F(i,0,b.size()) cout<<b[i]<<"\n";
}
