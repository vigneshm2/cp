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

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vi a(n);
        cin>>a;
        
        vi numsub(n); // number of subarrays with given value as max
        F(i,0,n){
            int num=1;
            for(int j=i-1;j>=0;j--) 
                if(a[i]>a[j]) num++;
            for(int j=i+1;j<n;j++) 
                if(a[i]>=a[j]) num++;
            numsub[i]=num;
        }
        
        vii a1(n);
        F(i,0,n) a1[i]=mp(a[i],i);
        sort(a1.rbegin(), a1.rend());
        
        vi prefsum(n);
        prefsum[0]=numsub[a1[0].second];
        F(i,1,n){
            prefsum[i]=prefsum[i-1]+numsub[a1[i].second];
        }
        // cout<<numsub<<"\n";
        // cout<<a1<<"\n";
        // cout<<prefsum<<"\n";
        
        F(i,0,m){
            int p;
            cin>>p;
            int idx = lower_bound(all(prefsum),p)-prefsum.begin();
            // cout<<idx<<" ";
            cout<<a[a1[idx].second]<<"\n";
        }
    }
}


