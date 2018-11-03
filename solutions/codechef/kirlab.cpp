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

ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a, a);
}

bool adj(int a, int b){
    return gcd(a,b)>1;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    
    const int np = 3200;
    int sprimes[np];
    F(i,0,np) sprimes[i]=1;
    sprimes[0]=sprimes[1]=0;
    F(i,0,np) if(sprimes[i])
        for(int j=2*i; j<np; j+=i) sprimes[j]=0;
    vi primes;
    F(i,0,np) if(sprimes[i]) primes.pb(i);
    int nprimes = primes.size();
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi a(n);
        cin>>a;
        
        vi maxl(nprimes);
        // maxl(i) = longest sequence ending at a number with factor primes[i]
        map<int, int> maxpl;
        // maxpl(i) = longest sequence ending in prime number i
        F(i,0,n){
            int currl = 1;
            int ispr = true;
            F(j,0,nprimes) if(a[i]%primes[j] == 0){
                currl = max(currl, maxl[j]+1);
                ispr = false;
            }
            // if(ispr) cout<<"big prime "<<a[i]<<"\n";
            if(ispr) currl = max(currl, maxpl[a[i]]+1);
            maxpl[a[i]] = max(maxpl[a[i]], currl);
            F(j,0,nprimes) if(a[i]%primes[j] == 0){
                maxl[j] = max(maxl[j], currl);
            }
        }
        // cout<<maxl<<"\n";
        int maxs = *max_element(all(maxl));
        int maxb = 0;
        for(auto it=maxpl.begin(); it!=maxpl.end(); ++it){
            maxb = max(maxb, it->second);
        }
        cout<<max(maxs,maxb)<<"\n";
    }
}


