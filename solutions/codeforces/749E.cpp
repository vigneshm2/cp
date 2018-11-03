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

const int N = 100100;
ll bit1[N], bit2[N];
// bit1 for count
// bit2 for -j sums

//query(idx) gives sum of values from 0 to idx
//update(idx,val) increases value at idx by val
void update(int idx,ll val, ll* bit){
    while(idx<=N){
        bit[idx]+=val;
        idx+=(idx & -idx);
    }
}
int query(int idx, ll* bit){
    ll sum=0;
    while(idx>0){
        sum+=bit[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    F(i,0,N) bit1[i]=bit2[i]=0;
    int n;
    cin>>n;
    double inv=0;
    double nsub=n;
    nsub=(nsub*(n-1))/2;
    double ns2=nsub+n;
    F(i,0,n){
        int x;
        cin>>x;
        x=n+1-x;
        double count=query(x, bit1);
        double jsum=query(x, bit2);
        update(x,1,bit1);
        update(x,i+1,bit2);
        
        inv += count;
        inv -= (jsum*(n-i))/ns2;
        
        // cout<<i<<" "<<((nsub+i)*count-jsum)/ns2<<"\n";
    }
    F(i,1,n+1){
        double c=i;
        c=c/4.0;
        c=c*(i-1);
        c=c*(n+1-i);
        inv+=c/ns2;
        // cout<<"perm "<<i<<" "<<c/ns2<<"\n";
    }
    printf("%.12lf\n",inv);
}


