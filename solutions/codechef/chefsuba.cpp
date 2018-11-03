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
    int n,k,p;
    cin>>n>>k>>p;
    vi a(n);
    cin>>a;
    string cmds;
    cin>>cmds;

    vi b(a);
    b.insert(b.end(), a.begin(), a.end());
    //vi val(2*n);
    //F(i,0,2*n-k+1){
        //F(j,i,i+k) val[i]+=b[i];
    //}
    vi psum(2*n);
    psum[0]=b[0];
    F(i,1,2*n) psum[i]=psum[i-1]+b[i];

    //cout<<val<<"\n";
    int idx=n;
    for(char c: cmds){
        if(c=='?'){
            //cout<<"st "<<idx<<" en "<<idx+n<<"\n";
            int st=idx, en=idx+n;
            int maxv=-INF;
            for(int i=st;i<en;i++){
                //printf("checking %d %d\n", i-1,min(en-1,i+k-1));
                maxv=max(maxv, psum[min(en-1,i+k-1)]-psum[i-1]);
            }
            cout<<maxv<<"\n";
        } else {
            idx--;
            if(idx==0) idx=n;
        }
    }
}


