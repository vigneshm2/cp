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
    int n1,m;
    cin>>n1>>m;
    int n=1<<n1;
    vi a(n);
    cin>>a;

    cout<<a<<"\n";
    vvi vals(n1+1);
    int cn=n, type=1; //type0=or, type1=xor
    F(i,0,n1+1){
        if(i==0) {
            vals[i]=a;
        } else {
            vals[i] = vi(cn);
            F(j,0,cn){
                if(type==0)
                    vals[i][j] = vals[i-1][2*j] | vals[i-1][2*j+1];
                else
                    vals[i][j] = vals[i-1][2*j] ^ vals[i-1][2*j+1];
            }
        }
        cn /=2;
        type = !type;
    }
    F(i,0,m){
        int p,b;
        cin>>p>>b;
        p--;
        int pid=p, type=1;
        F(i,0,n1+1){
            if(i==0)
                vals[0][pid]=b;
            else {
                int j = pid;
                if(type==0)
                    vals[i][j] = vals[i-1][2*j] | vals[i-1][2*j+1];
                else
                    vals[i][j] = vals[i-1][2*j] ^ vals[i-1][2*j+1];
            }
            pid/=2;
            type=!type;
        }
        cout<<vals[n1][0]<<"\n";
    }
}


