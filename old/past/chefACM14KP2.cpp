//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int INF = 1000000000;
const double PI =3.141592653589793238;
#pragma unused(INF,PI)
#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }

const int N = 100000;

int bit[N];

void update(int idx,int val){
    while(idx<=N){
        bit[idx]+=val;
        idx+=(idx & -idx);
    }
}

ll query(int idx){
    ll sum=0;
    while(idx>0){
        sum+=bit[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
#ifdef local_test
//    input
//    freopen("input","w",stdout);
//    cout<<"1 \n 100 10 \n";
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t;
    cin>>t;
    F(tt,0,t){
        int n,k;
        cin>>n>>k;
        vi a(n);
        F(i,0,n) cin>>a[i];
        vi b(a);
        sort(b.begin(),b.end());
        int dup=0;
        F(i,1,n) if(b[i]==b[i-1]) dup=1;
        F(i,0,N) bit[i]=0;
        ll inv=0;
        for(int i=n-1;i>=0;i--){
            inv+=query(a[i]-1);
            update(a[i],1);
        }
        //cout<<inv<<" "<<inv-k<<"\n";
        if(inv>=k){
            printf("Case %d: %lld\n",tt+1,(inv-k));
        } else {
            ll rem=k-inv;
            if(rem%2==0 || dup) printf("Case %d: %d\n",tt+1,0);
            else printf("Case %d: %d\n",tt+1,1);
        }
        
    }
}

