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
#include <cassert>
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
#pragma unused(INF,PI,LINF,mod)
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
ll modexp(ll a, ll exp){
    if(exp==0) return 1ll;
    ll temp =modexp((a*a)%mod,exp/2);
    return (exp%2==0)?temp:(a*temp)%mod;
}

const int maxn=1010;
ii a[maxn][maxn],tree[4*maxn][4*maxn];
int n,m;

ii merge(ii t1,ii t2){
    return mp(max(t1.first,t2.first),t1.second+t2.second);
}
ii zero(){
    return mp(-INF,0);
}

void buildy(int vx,int lx,int rx,int vy,int ly,int ry){
    // call v=1,l=0,r=n-1
    if(ly==ry){
        if(lx==rx)
            tree[vx][vy]=a[lx][ly];
        else
            tree[vx][vy]=merge(tree[vx*2][vy],tree[vx*2+1][vy]);
    } else {
        int mid=(ly+ry)/2;
        buildy(vx,lx,rx,2*vy,ly,mid);
        buildy(vx,lx,rx,2*vy+1,mid+1,ry);
        tree[vx][vy]=merge(tree[vx][2*vy],tree[vx][2*vy+1]);
    }
}

void buildx(int vx, int lx,int rx){
    // call v=1,l=0,r=n-1
    if(lx==rx){
        buildy(vx,lx,rx,1,0,m-1);
//        tree[v]=a[l];
    } else {
        int mid=(lx+rx)/2;
        buildx(2*vx,lx,mid);
        buildx(2*vx+1,mid+1,rx);
        buildy(vx,lx,rx,1,0,m-1);
//        tree[v]=merge(tree[2*v],tree[2*v+1]);
    }
}

ii queryy(int vx,int vy,int l,int r,int qly,int qry){
    // call v=1,l=0,r=n-1 to query from ql to qr(included)
    if(qly>qry)
        return zero();
    if(l==qly && r==qry)
        return tree[vx][vy];
    int mid=(l+r)/2;
    return merge(queryy(vx,2*vy,l,mid,qly,min(qry,mid)),
                 queryy(vx,2*vy+1,mid+1,r,max(qly,mid+1),qry));
}
ii queryx(int vx,int l,int r,int qlx,int qrx,int qly,int qry){
    // call v=1,l=0,r=n-1 to query from ql to qr(included)
    if(qlx>qrx)
        return zero();
    if(l==qlx && r==qrx)
        return queryy(vx,1,0,m-1,qly,qry);
//        return tree[v];
    int mid=(l+r)/2;
    return merge(queryx(2*vx,l,mid,qlx,min(qrx,mid),qly,qry),
                 queryx(2*vx+1,mid+1,r,max(qlx,mid+1),qrx,qly,qry));
}

//void update(int v,int l,int r,int idx,int val){
//    // call v=1,l=0,r=n-1 to update idx to val
//    if(l==r){
//        // may want to update a
//        tree[v]=val;
//    } else {
//        int mid=(l+r)/2;
//        if(idx<=mid) update(2*v,l,mid,idx,val);
//        else update(2*v+1,mid+1,r,idx,val);
//        tree[v]=merge(tree[2*v],tree[2*v+1]);
//    }
//}

void build(){
    buildx(1,0,n-1);
}
ii query(int x1,int y1,int x2,int y2){
    return queryx(1,0,n-1,x1,x2,y1,y2);
}

int max_score(int a,int b){
    int minv=INF;
    for(int i=0;i+a-1<n;i++) for(int j=0;j+b-1<m;j++){
        ii res=query(i,j,i+a-1,j+b-1);
//        cout<<"i:"<<i<<" j:"<<j<<" res:"<<res<<"\n";
        minv=min(minv,a*b*res.first-res.second);
    }
    return minv;
}
int main(int argc, const char * argv[]) {
#ifdef local_test
    // input
    //    freopen("input","w",stdout);
    //    cout<<"1000000\n";
    //    F(i,0,1000000) cout<<i<<"\n";
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t=1;
//    cin>>t;
    for(int tt=1;tt<=t;tt++){
//        int n,m;
        cin>>n>>m;
        int x;
        F(i,0,n) F(j,0,m) {
            cin>>x;
            a[i][j]=mp(x,x);
        }
        build();
        int q;
        cin>>q;
        F(i,0,q){
            int a,b;
            cin>>a>>b;
            cout<<max_score(a,b)<<"\n";
        }

    }
}
