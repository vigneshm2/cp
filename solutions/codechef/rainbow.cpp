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


int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m=(n*(n-1))/2;
        vvi cols(n,map<int,int>); // cols[i][j] = number of col j edges for vertex i
        F(i,0,n){
            F(j,0,n){
                int x;
                cin>>x;
                x--;
                if(x>=0)
                    cols[i][x]++;
            }
        }
        int done=false;
        int rem=n;
        
        while(!done && rem>=3){
            // F(i,0,n) cout<<cols[i]<<"\n";
            // remove row with all eq
            int got=false;
            F(i,0,n){
                if(got) break;
                int n_nz=0,c_nz;
                F(j,0,m) if(cols[i][j]>0){
                    n_nz++;
                    c_nz=j;
                }
                if(n_nz==1){
                    // printf("removing %d,%d\n",i,c_nz);
                    got=true;
                    cols[i][c_nz]=0;
                    F(j,0,n){
                        cols[j][c_nz]--;
                    }
                    rem--;
                    break;
                }
            }
            if(!got) 
                done=true;
        }
        
        if(done)
        cout<<rem<<"\n";
        else
        cout<<"0\n";
    }
}


