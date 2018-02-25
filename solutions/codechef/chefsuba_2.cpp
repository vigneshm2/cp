//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
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

class SegmentTree{

public:
    vi a,t;
    int n;

    int query(int l, int r){
        // get merge(a[l..r]);
        return query(1, 0, n-1,l ,r);
    }

    void update(int idx, int value){
        // set a[idx]=value
        update(1, 0, n-1, idx, value);
    }

    int merge(int l, int r){
        return max(l, r);
    }

    SegmentTree(vi &b){
        a = b;
        n = a.size();
        t = vi(4*n);
        build(1, 0, n-1);
    }

private:
    void build(int id, int l, int r){
        // build t[l,r] using a
        if(l==r) {
            t[id]=a[l];
        } else {
            int mid=(l+r)/2;
            build(2*id, l, mid);
            build(2*id+1, mid+1, r);
            t[id] = merge(t[2*id], t[2*id+1]);
        }
    }

    int query(int id, int l, int r, int lr, int rr){
        //printf("querying [%d,%d] in [%d,%d]\n",lr,rr,l,r);
        // get query for [lr,rr] in subarray [l,r]
        if(l==lr && r==rr)
            return t[id];
        int mid = (l+r)/2;
        if(lr>mid){
            // fully in r
            return query(2*id+1,mid+1,r,lr,rr);
        }
        if(rr <= mid){
            // fully in l
            return query(2*id, l, mid, lr, rr);
        }
        // in l and r
        int left = query(2*id, l, mid, lr, mid);
        int right = query(2*id+1, mid+1, r, mid+1, rr);
        return merge(left, right);
    }
    
    void update(int id, int l, int r, int idx, int value){
        if(l==r){
            t[id] = value;
            a[l] = value;
        } else {
            int mid = (l+r)/2;
            if(idx <= mid)
                update(2*id, l, mid, idx, value);
            else
                update(2*id+1, mid+1, r, idx, value);
            t[id] = merge(t[2*id], t[2*id+1]);
        }
    }

};


int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    int n,k,p;
    cin>>n>>k>>p;
    k=min(k,n);
    vi a(n);
    cin>>a;
    string mvs;
    cin>>mvs;
    assert(mvs.size()==p);

    vi b(n);
    vi psum(n);
    psum[0]=a[0];
    F(i,0,n-1) psum[i+1]=psum[i]+a[i+1];
    F(i,0,n-k+1) b[i]=psum[i+k-1]-(i>0?psum[i-1]:0);

    SegmentTree segt(b);
    //cout<<psum<<"\n";
    //cout<<b<<"\n\n";
    int pt=0;
    for(char c: mvs){
        //cout<<b<<"\n";
        if(c == '?'){
            int maxv=-1;
            //F(i,0,n) maxv=max(maxv,b[i]);
            maxv = segt.query(0,n-1);
            cout<<maxv<<"\n";
        } else {
            // st goes to beg, 
            int st = n-1-pt;
            int en = n-k-pt;
            if(en<0) en+=n;
            int nidx = (st+1)%n;
            int nv = segt.query(nidx, nidx);
            segt.update(st, nv + a[st] - a[(st+k)%n]);
            //if(st+k-1>=n){
                //F(i,st,n) b[st]+=a[i];
                //F(i,0,st+k-n) b[st]+=a[i];
            //} else {
                //F(i,st,st+k) b[st]+=a[i];
            //}
            //b[en]=(k==1?a[en]:0);
            segt.update(en,(k==1?a[en]:0)); 
            pt++;
            if(pt==n) pt=0;
        }
    } 
}


