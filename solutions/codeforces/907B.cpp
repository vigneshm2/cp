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

char chr(int i){
    if(i==0) return '.';
    else if(i==1) return 'x';
    else if(i==2) return 'o';
    else if(i==3) return '!';
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    vvi b(9,vi(9)); //0-. 1-x 2-o 3-!
    F(i,0,9) F(j,0,9){
        char c;
        cin>>c;
        if(c=='x') b[i][j]=1;
        else if(c=='o') b[i][j]=2;
    }
    int n,m;
    cin>>n>>m;
    n--;m--;
    int i1=n%3,i2=m%3;
    i1=i1*3,i2=i2*3;
    int ok=0;
    F(i,i1,i1+3) F(j,i2,i2+3){
        if(b[i][j]==0){
            ok=1;
            b[i][j]=3;
        }
    }
    if(!ok){
        F(i,0,9) F(j,0,9) if(b[i][j]==0) b[i][j]=3;
    }

    F(i,0,9){
        F(j,0,9){
            printf("%c",chr(b[i][j]));
            if(j%3==2) printf(" ");
        }
        if(i%3==2) printf("\n");
        printf("\n");
    }
}


