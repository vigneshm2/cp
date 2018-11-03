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
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int INF = 1000000000;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
#pragma unused(INF,PI,LINF)
#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){
    for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

const int N=10000005;
int primediv[N];
const int pN=3200;
int prime[pN];

ll primecalc(int p,int e){
    return (ll)((pow(p,2*e+1)+1)/(p+1));
}
ll calc(int n){
    if(n==1) return 1;
    int p=primediv[n],e=0;
    while(n%p==0) n/=p,e++;
    return primecalc(p,e)*calc(n);
}
int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}

int main(int argc, const char * argv[]) {
#ifdef local_test
//    input
//    freopen("input","w",stdout);
//    cout<<"1 \n 100 10 \n";
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    F(i,0,pN) prime[i]=1;
    prime[0]=prime[1]=0;
    F(i,0,pN) if(prime[i]) for(int j=2*i;j<pN;j+=i) prime[j]=0;
    F(i,0,N) primediv[i]=i;
    F(i,0,pN) if(prime[i])
        for(int j=2*i;j<N;j+=i)
            primediv[j]=i;
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        ll sum=0;
        printf("%lld\n",calc(n));
    }
}





