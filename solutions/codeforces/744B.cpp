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
#include <cstring>

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

#define F(i,a,n) for(int i=(a);i<(int)(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){
    for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    
    // ask q[i] = numbers with bit i=0
    // ask p[i] = numbers with bit i=1
    // min[i] = union()
    
    // n=8
    // q[0] = 0,2,4,6 p[0] = 1,3,5,7
    // q[1] = 0,1,4,5 p[1] = 2,3,6,7
    // q[2] = 0,1,2,3 p[2] = 4,5,6,7
    
    // min[0] = p[0],p[1],p[2]
    // min[1] = q[0],p[1],p[2]
    // etc...
    
    // n_max=1023 so 10 length
    int q[10][1023], p[10][1023];
    F(i,0,10) F(j,0,n) q[i][j]=p[i][j]=INF;
    F(i,0,10){
        vi cq,cp;
        F(j,0,n){
            if(j & (1<<i)) cp.push_back(j+1);
            else cq.push_back(j+1);
        }
        if(cp.size()>0){
            cout<<cp.size()<<"\n"<<cp<<"\n";
            fflush(stdout);
            F(j,0,n) cin>>p[i][j];
        }
        if(cq.size()<n){
            cout<<cq.size()<<"\n"<<cq<<"\n";
            fflush(stdout);
            F(j,0,n) cin>>q[i][j];
        }
    }
    cout<<"-1\n";
    F(j,0,n){
        int minv = INF;
        F(i,0,10){
            // printf("j: %d i: %d q_ij: %d, p_ij: %d\n",j,i,q[i][j],p[i][j]);
            if(j & (1<<i)) minv=min(minv, q[i][j]);
            else minv = min(minv, p[i][j]);
        }
        cout<<minv<<" ";
    }
}


