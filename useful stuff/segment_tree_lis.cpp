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

const int maxn=100010;
int a[maxn],tree[4*maxn];

int merge(int t1,int t2){
    return max(t1,t2);
}

void build(int v,int l,int r){
    // call v=1,l=0,r=n-1
    if(l==r){
        tree[v]=a[l];
    } else {
        int mid=(l+r)/2;
        build(2*v,l,mid);
        build(2*v+1,mid+1,r);
        tree[v]=merge(tree[2*v],tree[2*v+1]);
    }
}

int query(int v,int l,int r,int ql,int qr){
    // call v=1,l=0,r=n-1 to query from ql to qr(included)
    if(ql>qr)
        return 0;
    if(l==ql && r==qr)
        return tree[v];
    int mid=(l+r)/2;
    return merge(query(2*v,l,mid,ql,min(qr,mid)),
                 query(2*v+1,mid+1,r,max(ql,mid+1),qr));
}

void update(int v,int l,int r,int idx,int val){
    // call v=1,l=0,r=n-1 to update idx to val
    if(l==r){
        // may want to update a
        tree[v]=val;
    } else {
        int mid=(l+r)/2;
        if(idx<=mid) update(2*v,l,mid,idx,val);
        else update(2*v+1,mid+1,r,idx,val);
        tree[v]=merge(tree[2*v],tree[2*v+1]);
    }
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
    vi arr(n);
    F(i,0,n) cin>>arr[i];
    F(i,0,maxn) a[i]=0;
    vi b(arr);
    sort(b.begin(),b.end());
    auto it=unique(b.begin(),b.end());
    b.resize(distance(b.begin(),it));
    F(i,0,n) arr[i]=(int)(lower_bound(b.begin(),b.end(),arr[i])-b.begin())+1;
    //    cout<<a<<"\n";
    build(1,0,maxn-1);
    F(i,0,n){
        int q=query(1,0,maxn-1,0,arr[i]-1);
        update(1,0,maxn-1,arr[i],q+1);
    }
    cout<<query(1,0,maxn-1,0,maxn-1);
}

