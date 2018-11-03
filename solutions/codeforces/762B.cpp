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

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int a,b,c;
    cin>>a>>b>>c;
    int m;
    cin>>m;
    vector<int> usb,ps2;
    F(i,0,m){
        int c;string type;
        cin>>c>>type;
        if(type=="USB") usb.pb(c);
        else ps2.pb(c);
    }
    sort(all(usb));
    sort(all(ps2));
    ll cost=0; int count=0;
    int last_u=min(a,(int)usb.size()), last_p=min(b,(int)ps2.size());
    F(i,0,last_u) cost+=usb[i];
    count+=last_u;
    F(i,0,last_p) cost+=ps2[i];
    count+=last_p;
    
    vector<int> mleft(usb.begin()+last_u,usb.end());
    mleft.insert(mleft.end(),ps2.begin()+last_p,ps2.end());
    sort(all(mleft));
    int last_b=min(c,(int)mleft.size());
    F(i,0,last_b) cost+=mleft[i];
    count+=last_b;
    cout<<count<<" "<<cost<<"\n";
}


