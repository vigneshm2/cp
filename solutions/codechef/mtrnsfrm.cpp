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
typedef vector<ll> vi;
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
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vvi a(n,vi(m));
        vvi b(a);
        F(i,0,n) cin>>a[i];
        F(i,0,n) cin>>b[i];
        F(i,0,n) F(j,0,m) b[i][j]-=a[i][j];
        // get b[i][j] using 1-col and 1-row 
        vi cdiffs(m),rdiffs(n); // cdiff[i]=b[_][i]-b[_][0] -> should be const for _
        F(i,0,m-1) cdiffs[i+1]=b[0][i+1]-b[0][0];
        F(i,0,n-1) rdiffs[i+1]=b[i+1][0]-b[0][0];
        // check const
        int ok=true;
        F(i,0,n) F(j,0,m) {
            if(b[i][j]-b[i][0]!=cdiffs[j]) ok=false;
            if(b[i][j]-b[0][j]!=rdiffs[i]) ok=false;
        }
        if(!ok){
            cout<<"-1\n";
            continue;
        }
        // cout<<cdiffs<<"\n"<<rdiffs<<"\n";
        ll constsum=b[0][0];
        vi diffs(n+m);
        F(i,0,m) diffs[i]=-cdiffs[i];
        F(i,0,n) diffs[i+m]=(constsum+rdiffs[i]);
        sort(all(diffs));
        // cout<<b<<"\n";
        // cout<<diffs<<"\n";
        int mid=(n+m-1)/2;
        ll cv=diffs[mid],rv=constsum-cv;
        ll cost=0;
        F(i,0,m) cost+=abs(cv+cdiffs[i]);
        F(i,0,n) cost+=abs(rv+rdiffs[i]);
        // cout<<cdiffs<<"\n"<<rdiffs<<"\n";
        // printf("cv %d rv %d\n",cv,rv);
        // cout<<cost<<"\n";
        if(mid+1<n+m){
            ll cost2=0;
            cv=diffs[mid+1],rv=constsum-cv;
            // printf("cv %d rv %d\n",cv,rv);
            F(i,0,m) cost2+=abs(cv+cdiffs[i]);
            F(i,0,n) cost2+=abs(rv+rdiffs[i]);
            // cout<<cost2<<"\n";
            cost=min(cost,cost2);
        }
        cout<<cost<<"\n";
    }
}


