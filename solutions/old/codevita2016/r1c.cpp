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
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

const int maxp = 560000;
int primes[maxp];
void findprimes(){
    F(i,0,maxp) primes[i]=1;
    primes[0]=primes[1]=0;
    F(i,0,maxp) if(primes[i]) for(int j=2*i;j<maxp;j+=i) primes[j]=0;
}
int isprime(ll n){
    int pm=(int)sqrt(n)+1;
    for(int p=2;p<=pm;p++){
        if(!primes[p]) continue;
        if(n%p==0) return 0;
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    findprimes();
    ll n;
    cin>>n;
    ll sum=2, count=0;
    F(p,3,maxp){
        if(primes[p]) {
            sum+=p;
            if(sum>n) {
                cout<<"stopping at prime "<<p<<" with sum "<<sum<<"\n";
                break;
            }
            if(isprime(sum)) {
                cout<<"got prime "<<sum<<"\n";
                count++;
            }
        }
    }
    cout<<count;
}


