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

int check(int n, int m, vi x){
    // neighbours of x= x+1,x-1,x+m,x-m
    int ok=1;
    F(i,0,n) F(j,0,m){
        if(!ok) break;
        set<int> on,cn;
        int curr=x[m*i+j];
        if(i>0) cn.insert(x[m*(i-1)+j]);
        if(i<n-1) cn.insert(x[m*(i+1)+j]);
        if(j>0) cn.insert(x[m*i+j-1]);
        if(j<m-1) cn.insert(x[m*i+j+1]);
        int cr=curr/m,cc=curr%m;
        if(cr>0) on.insert(m*(cr-1)+cc);
        if(cr<n-1) on.insert(m*(cr+1)+cc);
        if(cc>0) on.insert(m*(cr)+cc-1);
        if(cc<m-1) on.insert(m*(cr)+cc+1);
        //cout<<on<<"\n"<<cn<<"\n";
        for(int cne: cn){
            if(on.count(cne)){
                ok=0;
                break;
            }
        }
    }
    return ok;
}
void seq(int n, int type, vi &x){
    if(n==4){
        if(type==1) x={1,3,0,2};
        else x={2,0,3,1};
    } else {
        if(type==1){
            F(i,0,(n+1)/2) x[i]=2*i;
            F(i,0,(n)/2) x[i+(n+1)/2]=2*i+1;
        } else {
            F(i,0,(n)/2) x[i]=2*i+1;
            F(i,0,(n+1)/2) x[i+(n)/2]=2*i;
        }
    }
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    if(n<4 && m<4){
        vi x(n*m);
        F(i,0,n*m) x[i]=i;
        int ok=0;
        do{
            if(check(n,m,x)) {
                ok=1;
                break;
            }
        }while(next_permutation(all(x)));
        if(ok){
            cout<<"YES\n";
            F(j,0,m) {F(i,0,n) cout<<x[i*m+j]+1<<" "; cout<<"\n";}
        }else
            cout<<"NO\n";
    } else {
        if(m>=4){
            vi y1(m),y2(m);
            seq(m,1,y1);
            seq(m,2,y2);
            vvi y(n, vi(m));
            F(i,0,n){
                if(i%2==0) F(j,0,m) y[i][j]=y1[j]+m*i;
                else F(j,0,m) y[i][j]=y2[j]+m*i;
            }
            cout<<"YES\n";
            F(i,0,n) {F(j,0,m) cout<<y[i][j]+1<<" "; cout<<"\n";}
        } else {

            vi y1(n),y2(n);
            seq(n,1,y1);
            seq(n,2,y2);
            vvi y(n, vi(m));
            F(i,0,m){
                if(i%2==0) F(j,0,n) y[j][i]=m*y1[j]+i;
                else F(j,0,n) y[j][i]=m*y2[j]+i;
            }
            cout<<"YES\n";
            F(i,0,n) {F(j,0,m) cout<<y[i][j]+1<<" "; cout<<"\n";}
        }
    }
}


