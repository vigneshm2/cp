//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <stack>
#include <set>

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

const int maxn = 100010;
int bit[maxn]; // gives max value in 0:k

void update(int idx,int val){
    while(idx<=maxn){
        bit[idx]=max(bit[idx],val);
        idx+=(idx & -idx);
    }
}

int query(int idx){
    int val=0;
    while(idx>0){
        val=max(val,bit[idx]);
        idx-=(idx & -idx);
    }
    return val;
}

int main(int argc, const char * argv[]) {
#ifdef local_test
    //    input
    //    freopen("input","w",stdout);
    //    cout<<"6 5 \n 0 1 1 2 4 3 1 4 4 5";
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n;
    cin>>n;
    vi a(n);
    F(i,0,n) cin>>a[i];
    vi b(a);
    sort(b.begin(),b.end());
    auto it=unique(b.begin(),b.end());
    b.resize(distance(b.begin(),it));
    F(i,0,n) a[i]=(int)(lower_bound(b.begin(),b.end(),a[i])-b.begin())+1;
//    cout<<a<<"\n";
    F(i,0,maxn) bit[i]=0;
    F(i,0,n){
        update(a[i],query(a[i]-1)+1);
    }
    cout<<query(maxn);
}

