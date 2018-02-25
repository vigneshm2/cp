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

int N=70;
vi itoda(ll x){
    vi a(N);
    F(i,0,N){
        a[i]=x%2;
        x/=2;
    }
    return a;
}

ll datoi(vi a){
    ll x=0;
    for(int i=N-1;i>=0;i--){
        x=2*x+a[i];
        //cout<<x<<"\n";
    }
    return x;
}

vi maxor(vi a, vi b){
    int ch=0;
    for(int i=N-1;i>=0;i--){
        if(ch) a[i]=1;
        else if(a[i]!=b[i]) {
            ch=1;
            a[i]=1;
        } else {
            a[i]=0;
        }
    }
    if(ch==0) return vi(N);
    return a;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    ll a,b;
    cin>>a>>b;
    vi ad=itoda(a),bd=itoda(b);
    //cout<<ad<<"\n"<<bd<<"\n";
    vi mx=maxor(ad,bd);
    //cout<<mx<<"\n";
    cout<<datoi(mx)<<"\n";
}



