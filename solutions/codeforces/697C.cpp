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

string bin(ll n){
    string s;
    while(n>0){
        s.pb(n%2+'0');
        n/=2;
    }
    reverse(all(s));
    return s;
}
string lca(string a, string b){
    int i=0;
    while(i<a.size() && i<b.size() && a[i]==b[i]) i++;
    return a.substr(0,i);
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    
    int q;
    cin>>q;
    map<string, ll> weights;
    F(i,0,q){
        char t;
        cin>>t;
        if(t=='1'){
            ll u,v,w;
            cin>>u>>v>>w;
            string ub = bin(u), vb = bin(v);
            string a = lca(ub, vb);
            while(ub.size()>a.size()) weights[ub]+=w, ub.pop_back();
            while(vb.size()>a.size()) weights[vb]+=w, vb.pop_back();
        } else {
            ll u,v;
            cin>>u>>v;
            string ub = bin(u), vb = bin(v);
            string a = lca(ub, vb);
            ll score=0;
            while(ub.size()>a.size()) score+=weights[ub], ub.pop_back();
            while(vb.size()>a.size()) score+=weights[vb], vb.pop_back();
            cout<<score<<"\n";
        }
    }
    
}


