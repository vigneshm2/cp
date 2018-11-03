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
    int n,m;
    cin>>n>>m;
    set<string> s1,s2;
    F(i,0,n){
        string s;
        cin>>s;
        s1.insert(s);
    }
    F(i,0,m){
        string s;
        cin>>s;
        s2.insert(s);
    }
    set<string> common;
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(common, common.begin()));
    int n1=n,n2=m,c=common.size();
    int win=0;
    while(!win){
        // printf("%d %d %d\n",n1,n2,c);
        if(n1==0) {
            win=2;
            break;
        }
        //p1
        if(c>0) c--,n1--,n2--;
        else n1--;
        //p2
        if(n2==0) {
            win=1;
            break;
        }
        if(c>0) c--,n1--,n2--;
        else n2--;
    }
    if(win==1) cout<<"YES\n";
    else cout<<"NO\n";
}


