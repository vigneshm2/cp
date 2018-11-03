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

#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){
    for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }
template<typename T1, typename T2> ostream& operator<<(ostream &s,map<T1, T2> &t){
    for(auto& kv: t) s<<"("<<kv.first<<","<<kv.second<<") "; return s; }

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<string> ni1(n),ni2(n);
    F(i,0,n) cin>>ni1[i]>>ni2[i];
    vector<string> n1(n),n2(n);
    F(i,0,n) {
        string x = ni1[i].substr(0,3);
        n1[i]=x;
        x[2]=ni2[i][0];
        n2[i]=x;
    }
    map<string,vi> n1map;
    F(i,0,n) n1map[n1[i]].pb(i);
    set<string> names;
    vector<string> ns(n);
    int ok=true;
    for(auto& kv: n1map){
        if(!ok) break;
        if(kv.second.size() > 1){
            for(int i: kv.second){
                string chosen = n2[i];
                if(names.count(chosen)) {
                    ok=false;
                    break;
                } else {
                    if(n1[i]==n2[i]){
                        ok=false;
                        break;
                    }
                    ns[i]=chosen;
                    names.insert(chosen);
                }
            }
        }
    }
    for(auto& kv: n1map){
        if(!ok) break;
        if(kv.second.size() == 1){
            int i = kv.second[0];
            if(!names.count(n1[i])){
                names.insert(n1[i]);
                ns[i]=n1[i];
            } else if(!names.count(n2[i])){
                names.insert(n2[i]);
                ns[i]=n2[i];
            } else {
                ok=false;
            }
        }
    }
    if(ok){
        cout<<"YES\n";
        F(i,0,n) cout<<ns[i]<<"\n";
    } else {
        cout<<"NO\n";
    }
}


