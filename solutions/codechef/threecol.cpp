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

typedef vector<vector<char>> vvc;
typedef vector<char> vc;

int nprint;
void print(int u1,int u2,int v1,int v2){
    nprint++;
    printf("%d %d %d %d\n",u1,u2,v1,v2);
}

void inc_ops(vii &ops, int inc){
    F(i,0,ops.size()){
        ops[i].first+=inc;
        ops[i].second+=inc;
    }
}
vii row_ops(int n){
    if(n==4){
        return vii{
            mp(1,2),
            mp(3,4),
            mp(2,3),
            mp(1,2),
            mp(2,3),
            mp(1,2),
            mp(3,4),
        };
    } else if(n==5){
        vii ops;
        vii op=row_ops(4);
        ops.insert(ops.begin(),op.begin(),op.end());
        ops.push_back(mp(4,5));
        ops.insert(ops.end(),all(op));
        return ops;
    } else if(n==8){
        vii ops;
        vii op5=row_ops(5);
        ops.insert(ops.begin(),all(op5));
        vii op5_(op5);
        inc_ops(op5_,3);
        ops.insert(ops.begin(),all(op5_));
        ops.insert(ops.begin(),all(op5));
        return ops;
    } else if(n==11){
        vii ops;
        vii op4=row_ops(4);
        inc_ops(op4,7);
        ops.insert(ops.begin(),all(op4));
        vii op8=row_ops(8);
        ops.insert(ops.end(),all(op8));
        vii op5=row_ops(5);
        inc_ops(op5,6);
        ops.insert(ops.end(),all(op5));
        // vii op8=row_ops(8);
        // vii op5=row_ops(5);
        // ops.insert(ops.end(),all(op8));
        // vii op5_1(op5);
        // inc_ops(op5_1,6);
        // ops.insert(ops.end(),all(op5_1));
        // vii op5_2(op5);
        // inc_ops(op5_2,3);
        // ops.insert(ops.end(),all(op5_2));
        // ops.insert(ops.end(),all(op5));
        return ops;
    } else {
        vii ops;
        // do last 4
        vii op4 = row_ops(4);
        inc_ops(op4, n-4);
        ops.insert(ops.end(), all(op4));
        // do first n-3
        vii opn3 = row_ops(n-3);
        ops.insert(ops.end(), all(opn3));
        // do last 5
        vii op5 = row_ops(5);
        inc_ops(op5, n-5);
        ops.insert(ops.end(), all(op5));
        return ops;
    }
    return vii();
}
void fix_single_row(int n, int r, bool isrow){
    vii ops = row_ops(n);
    for(ii op: ops){
        if(isrow)
            print(r,op.first,r,op.second);
        else
            print(op.first,r,op.second,r);
    }
}

void fix_all(int n){
    vii ops = row_ops(n);
    printf("%d\n",2*n*ops.size());
    F(i,1,n+1) fix_single_row(n,i,true);
    F(i,1,n+1) fix_single_row(n,i,false);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    nprint=0;
    if(n==2){
        printf("4\n");
        printf("1 1 1 2\n2 1 2 2\n");
        printf("1 1 2 1\n1 2 2 2\n");
    } else if(n==4){
        // printf("56\n");
        fix_all(4);
    } else if(n==5){
        // printf("150\n");
        fix_all(5);
    } else if(n==8){
        // printf("720\n");
        fix_all(8);
    } else if(n==11){
        // printf("1980\n");
        fix_all(n);
    } else {
        fix_all(n);
        // printf("%d\n",nprint);
    }
        
        // printf("%d\n",nprint);
}


