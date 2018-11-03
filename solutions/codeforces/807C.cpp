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

    int t;
    cin>>t;
    while(t--){
        ll x,y,p,q;
        cin>>x>>y>>p>>q;
        // x+a=kp, y+b=kq, a<=b
        /*
         * b-a = kq-y-kp+x = k(q-p) -(y-x)
         * q-p=0  OR k exists
         * x=36 y=38 p=0 q=1
         * b-a = 
         */
        if(p==q && x!=y) cout<<-1<<"\n";
        else {

            // find first index where check is true 
            ll l=1,r=1000000000,mid;
            ll a,b;
            while(l<r){
                mid=l+(r-l)/2;
                int check;
                ll k = mid;
                a=k*p-x,b=k*q-y;
                check = (a>=0) && (b>=0) && (a<=b);
                //printf("l %lld r %lld true mid %lld check %d\n",l,r,mid,check);
                if(check) r=mid;
                else l=mid+1;
            }
            a = l*p-x,b=l*q-y;
            int check = (a>=0) && (b>=0) && (a<=b);
            if(check)
                cout<<b<<"\n";
            else
                cout<<"-1\n";
            //cout<<a<<" "<<b<<"\n";
        }
    }
}


