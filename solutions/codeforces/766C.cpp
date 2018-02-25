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
typedef vector<vii> vvii;

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

vector<ll> countways(string& s, int n, vi& lim){
    vector<ll> d(n);
    vi minp(n,n);
    int longest=1;
    d[0]=1;
    minp[0]=1;
    F(k,1,n){
        int clim=lim[s[k]-'a'];
        for(int i=k;i>=0;i--){
            char c=s[i]-'a';
            clim=min(clim,lim[c]);
            if(clim<k-i+1) break;
            else {
                
                longest = max(longest,k-i+1);
                if(i>=1){
                    d[k]+=d[i-1];
                    d[k]=d[k]%mod;
                    minp[k]=min(minp[k],minp[i-1]+1);
                }else{
                    d[k]+=1;
                    minp[k]=min(minp[k],1);
                }
            }
        }
    }
    // cout<<d<<"\n";
    return {d[n-1],longest,minp[n-1]};
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi lim(26);
    cin>>lim;
    vector<ll> res=countways(s,n,lim);
    cout<<res[0]<<"\n"<<res[1]<<"\n"<<res[2]<<"\n";
}


