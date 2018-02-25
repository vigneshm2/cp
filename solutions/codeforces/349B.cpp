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

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int v;
    vi dig(9);
    cin>>v;
    cin>>dig;
    
    auto it = dig.begin();
    F(i,0,9) if(dig[i]<=*it) it=dig.begin()+i;
    int min_dig_v = *it;
    int mind_count = v/min_dig_v;
    int left = v - mind_count*min_dig_v + min_dig_v;
    int min_dig = it-dig.begin()+1;
    
    vi ans(mind_count, min_dig);
    
    F(i,0,mind_count){
        // try to improve ans[i];
        for(int d=8; d>=0; d--){
            if(dig[d]<=left){
                // cout<<"got d"<<d<<"\n";
                ans[i]=d+1;
                left = left - dig[d] + min_dig_v;
                break;
            }
        }
    }
    
    if(mind_count==0) cout<<-1<<"\n";
    else{
        F(i,0,ans.size()) cout<<ans[i];
    }
}


