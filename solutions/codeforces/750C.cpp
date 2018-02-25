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

int n;
vi divs,changes;

int div_matches(int rating, int div){
    if(div==1) return rating>=1900;
    else return rating<1900;
}
int is_poss(int rating, int* final){
    F(i,0,n){
        // cout<<rating<<"\n";
        if(div_matches(rating, divs[i])){
            rating += changes[i];
        } else {
            return false;
        }
    }
    *final = rating;
    return true;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    cin>>n;
    divs.resize(n);
    changes.resize(n);
    F(i,0,n) cin>>changes[i]>>divs[i];
    
    ll low=0, up=LINF;
    if(divs[0] == 1){
        low=1900;
    } else {
        up=1899;
    }
    ll sum_so_far=0;
    F(i,0,n){
        if(divs[i]==1){
            // low+sum >= 1900
            low = max(low, 1900-sum_so_far);
        } else {
            // up+sum <= 1899
            up = min(up, 1899-sum_so_far);
        }
        sum_so_far += changes[i];
    }
    // cout<<up<<" "<<low<<"\n";
    int final;
    if(up>LINF/2) cout<<"Infinity\n";
    else if(is_poss(up, &final)) cout<<final<<"\n";
    else cout<<"Impossible";
}


