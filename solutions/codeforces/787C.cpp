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
    int k1;
    cin>>k1;
    vi rs(k1);
    cin>>rs;
    int k2;
    cin>>k2;
    vi ms(k2);
    cin>>ms;
    
    vi rw(n),mw(n); // -1->L 0->? 1->W 2->T
    rw[0]=mw[0]=-1;
    int ch=1;
    while(ch){
        ch=0;
        // r
        F(i,0,n){
            if(rw[i]!=0) continue;
            int rwi=rw[i];
            int hl=0,ht=0;
            F(j,0,k1){
                int idx=(i+rs[j])%n;
                if(mw[idx]==-1) hl=1;
                else if(mw[idx]==0) ht=1;
            }
            if(hl) rw[i]=1;
            else if(ht) rw[i]=0;
            else rw[i]=-1;
            if(rwi!=rw[i]) ch=1;
        }
        F(i,0,n){
            if(mw[i]!=0) continue;
            int mwi=mw[i];
            int hl=0,ht=0;
            F(j,0,k2){
                int idx=(i+ms[j])%n;
                if(rw[idx]==-1) hl=1;
                else if(rw[idx]==0) ht=1;
            }
            if(hl) mw[i]=1;
            else if(ht) mw[i]=0;
            else mw[i]=-1;
            if(mwi!=mw[i]) ch=1;
        }
        // cout<<rw<<"\n";
        // cout<<mw<<"\n";
    }
    F(i,1,n) if(rw[i]==-1) cout<<"Lose ";
    else if(rw[i]==0) cout<<"Loop ";
    else cout<<"Win ";
    cout<<"\n";
    F(i,1,n) if(mw[i]==-1) cout<<"Lose ";
    else if(mw[i]==0) cout<<"Loop ";
    else cout<<"Win ";
    cout<<"\n";
}


