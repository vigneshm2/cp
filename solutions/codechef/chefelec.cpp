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
    int t;
    cin>>t;
    F(tc,0,t){
        int n;
        cin>>n;
        string elec;
        cin>>elec;
        vi x(n);
        cin>>x;
        int st=-1,en=-1,in0=false;
        vii streaks;
        F(i,0,n){
            if(elec[i]=='0'){
                if(!in0)
                    st=i,in0=true;
            } else {
                if(in0) {
                    en=i-1;
                    streaks.pb(mp(st,en));
                    in0=false;
                }
            }
        }
        if(in0) en=n-1,streaks.pb(mp(st,en));
        int tot=0;
        // cout<<streaks<<"\n";
        for(ii streak : streaks){
            int can_rem=true;
            int start=streak.first-1;
            if(start<0) can_rem=false,start=0;
            int end=streak.second+1;
            if(end>=n) can_rem=false,end=n-1;
            // cout<<start<<" "<<end<<"\n";
            int sum=x[end]-x[start],maxv=0;
            if(can_rem){
                F(i,start,end)
                    maxv=max(maxv,x[i+1]-x[i]);
                tot+=sum-maxv;
            } else {
                tot += sum;
            }
        }
        cout<<tot<<"\n";
    }
}


