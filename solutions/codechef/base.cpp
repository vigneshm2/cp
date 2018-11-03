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
#include <iomanip>
 
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
 
int is_start_1(ll n, ll b){
    // does n start with 1 in base b
    if(n==0) return 0;
    if(b==1) return 1;
    int guard=0;
    while(n>=b && guard++<100) n=n/b;
    return n==1;
}
 
void print_base(ll n, ll b){
    vi digs;
    while(n>0){
        digs.pb(n%b);
        n/=b;
    }
    reverse(all(digs));
    cout<<digs<<"\n";
}

ll count_brute(ll n){
    ll count=0;
    for(ll b=2; b<=n; b++){
        count+=is_start_1(n, b);
    }
    return count;
}

ll count_sqrt(ll n){
    ll count =0 ;
    ll sqrtl = ceil(sqrt(n));
    for(ll b=2; b<=sqrtl; b++){
        int t= is_start_1(n,b);
        // if(t && b<=1000) cout<<b<<" ";
        count+=t;
    }
    count += (n+1)/2;
    return count;
}

ll exponent(ll a, ll e){
    if(e==0) return 1;
    if(e%2==0) return exponent(a*a,e/2);
    else return a*exponent(a*a,e/2);
}
ll floor_root(double n, double e){
    // finds floor(e-th root(n))
    double d = pow(n, 1.0/e);
    ll d2 = floor(d);
    if(exponent(d2+1,e)<=n) return d2+1;
    if(exponent(d2,e)>n) return d2-1;
    return d2;
}
ll count_gen(ll n){
    ll count = 0;
    // count += (n+1)/2;
    int rtlim = ceil(log(n)/log(10)+1);
    double eps = 1e-11;
    for(double rt=1.0; rt<=rtlim; rt+=1.0){
        ll rt_end = floor_root(n, rt);
        ll rt_start = floor_root(n/2.0, rt)+1;
        count += max(rt_end - max(10ll,rt_start)+1, 0ll);
        // if(rt>1.0 && rt_start!=10) for(ll i=rt_start; i<=rt_end; i++){
            // if(!is_start_1(n,i)) cout<<"error at "<<n<<", "<<i<<"\n";
        // }
        // if(is_start_1(n,rt_start-1)) cout<<"missed "<<rt_start-1<<"\n";
        // if(is_start_1(n,rt_end+1)) cout<<"missed "<<rt_end+1<<"\n";
        // if(rt_start==10) {
            // count += is_start_1(n,10);
            // rt_start=11;
        // }
        // cout<<"sqrt "<<rt<<" count "<<max(rt_end - max(10ll,rt_start)+1, 0ll)<<"\n";
        // cout<<rt_start<<" to "<<rt_end<<"\n";
        // printf("%.12lf to %.12lf\n",pow(n/2, 1.0/rt)+1,pow(n, 1.0/rt));
        // printf("%lld to %lld\n",floor_root(n/2.0, rt)+1,floor_root(n, rt));
    }
    for(ll b=2; b<10; b++){
        // if(is_start_1(n, b)) cout<<"small val "<<b<<"\n";
        count+=is_start_1(n, b);
    }
    return count;
}
 
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    if(1){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<"INFINITY\n";
        } else {
            if(n<1000){
                cout<<count_brute(n)<<"\n";
            } else {
                // cout<<"actual: "<<count_sqrt(n)<<"\n";
                cout<<count_gen(n)<<"\n";
            }
        }
    }
    }else{
    cout<<setprecision(10);
    ll end = 1e12, count=1000ll;
    ll st = end-count;
    // end = 1000000, st=1000;
    for(ll n=st; n<end; n++){
        if(n%100==0) cout<<"done "<<n<<endl;
        if(count_sqrt(n)!=count_gen(n))
        cout<<"unmatched at "<<n<<"\n";
    }
    }
}
 