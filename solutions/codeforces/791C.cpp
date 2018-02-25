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

string int_to_string(int n){
    char c[3];
    c[0]=n/26+'A';
    c[1]=n%26+'a';
    c[2]='\0';
    return string(c);
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,k;
    cin>>n>>k;
    int d=n-k+1;
    vi vals(d);
    F(i,0,d){
        string s;
        cin>>s;
        vals[i]=(s=="YES");
    }
    vi nums(n);
    int c=0;
    F(i,0,d){
        // fill till 0-index i+k-1
        if(i==0){
            if(vals[i]) F(i,0,k) nums[i]=c++;
            else {
                nums[0]=nums[1]=0;
                c=1;
                F(i,2,k) nums[i]=c++;
            }
        } else {
            if(!vals[i]) nums[i+k-1]=nums[i];
            else nums[i+k-1]=c++;
        }
    }
    F(i,0,n) cout<<int_to_string(nums[i])<<" ";
}


