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

int imod(int n, int d, int* q){
  *q = n/d;
  int r=n%d;
  if(r<0){
    if(d>0){
      *q -= 1;
      r += d;
    } else {
      *q += 1;
      r -= d;
    }
  }
  return r;
}
string to_base(int n, int to){
  // converts given val to base 'to'
  string num;
  if(n==0) return "0";
  int mn=0;
  if(n<0 && to>0){
    mn=1;
    n=-n;
  }
  int lim=100;
  while(n!=0 && (lim--)){
    // printf("n %d\n",n);
    int r = imod(n, to, &n);
    num.pb(r+'0');
  }
  if(mn)
    num.pb('-');
  reverse(all(num));
  return num;
}
int from_base(string n, int from){
  // converts n to val from base
  int val=0;
  F(i,0,n.size()){
    val=val*from+(n[i]-'0');
  }
  return val;
}
int extract_base(string s){
  int mpos = s.find_first_of('-');
  string basenum = s.substr(mpos+1);
  return stoi(basenum);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    while(1){
      string s;
      cin>>s;
      if(s=="end") break;
      int base = extract_base(s);
      if(s[0]=='f'){
        //from
        string num;
        cin>>num;
        cout<<from_base(num, -base)<<"\n";
      } else {
        //to
        int val;
        cin>>val;
        cout<<to_base(val, -base)<<"\n";
      }
    }
}
