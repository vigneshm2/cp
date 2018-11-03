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

class Mexset{
public:
    int k;
    set<int> excluded;
    multiset<int> inset;

    Mexset(int ink){
        k = ink;
        F(i,0,k+1) excluded.insert(i);
    }
    void insert(int x){
        //cout<<excluded<<"\n";
        if(x > k) return;
        if(excluded.count(x)) excluded.erase(x);
        inset.insert(x);
    }
    void remove(int x){
        if(x > k) return;
        if(inset.count(x)==1){
            inset.erase(x);
            excluded.insert(x);
        } else {
            inset.erase(inset.find(x));
        }
    }
    int ok(){
        if(!excluded.empty()){
            //printf("mex %d\n",*excluded.begin());
        }
        return !excluded.empty();
    }
   
};

ll modpow(ll a, int exp){
    if(exp==0) return 1ll;
    if(exp%2==0) return modpow((a*a)%mod,exp/2);
    else return (a*modpow((a*a)%mod,exp/2))%mod;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    int n,k;
    cin>>n>>k;
    vi a(n);
    cin>>a;

    //cout<<a<<"\n";

    if(k>n){
        // 2**n-1
        cout<<modpow(2,n-1)<<"\n";
    } else {
        Mexset m(k);
        vi ends(n);
        int st = 0;
        F(i,0,n){
            // m is ok at start
            m.insert(a[i]);
            while(!m.ok() && st<=i){
                m.remove(a[st]);
                st++;
            }
            ends[i] = st;
        }
        //cout<<ends<<"\n";

        vll f(n);
        vll fsums(n);
        F(i,0,n){
            f[i] = (ends[i]==0)?1:0;
            int st = max(0, ends[i]-1);
            //F(j,st,i) f[i]+=f[j];
            if(i>0){
                f[i] += fsums[i-1] - (st>0?fsums[st-1]:0) + mod;
                f[i] = f[i] % mod;
                fsums[i] = (fsums[i-1] + f[i])%mod;
            } else {
                fsums[i] = f[i];
            }
        }

        //cout<<fsums<<"\n";
        //cout<<f<<"\n";
        cout<<f[n-1]<<"\n";
    }
    
}


