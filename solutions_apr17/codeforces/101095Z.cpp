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

int pos(int i, int k, int n){
  // pos(0..n-1) of dancer i (1..n) after k steps
  int p;
  if(i%2==1)
    p=(i+k-1)%n;
  else
    p=(i-k-1)%n;
  if(p<0) p+=n;
  return p;
}
int posi(int pos, int k, int n){
  // dancer at positon pos after steps
  int i;
  if((pos+k)%2==0)
    i=(pos-k)%n;
  else
    i=(pos+k)%n;
  if(i<0) i+=n;
  return i+1;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,d,k;
    cin>>d>>k>>n;
    int pos_k = pos(k,n,d);
    int pos_l = (pos_k+1)%d,pos_r = (pos_k-1+d)%d;
    cout<<posi(pos_l,n,d)<<" "<<posi(pos_r,n,d)<<"\n";
}
