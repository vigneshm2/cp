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

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vi a(n);
        cin>>a;

        sort(all(a));
        vll psums(n);
        psums[0] = a[0];
        F(i,1,n) psums[i] = psums[i-1]+a[i];

        F(i,0,q){
            int k;
            cin>>k;

            auto high_st_it = lower_bound(all(a), k);
            int high_st = high_st_it - a.begin();
            // high_st .. end -> count directly
            // begin.. high_st -> try to increase
            //int available = high_st;
            //cout<<high_st<<"\n";
            //int curr = high_st - 1;
            int count = n - high_st;
            ////cout<<"direct "<<count<<"\n";
            //while(available && curr>=0){
                //// try to increase one;
                ////printf("try a[%d] = %d\n",curr, a[curr]);
                //int diff = k-a[curr];
                ////printf("avialable %d diff %d\n", available, diff);
                //available--;
                //if(available < diff) break;
                //available -= diff;
                //curr--;
                //count++;
            //}
            //cout<<count<<"\n";
            

            // find first index where check is true 
            ll l=0,r=high_st+5,mid;
            while(l<r){
                mid=l+(r-l)/2;
                int check;
                // check 0 <= mid < high_st
                if(mid<0 || mid >= high_st) check=1;
                else {
                    // [0..mid-1] used up and [mid..high_st) increased
                    int available = mid;
                    ll needed = 0;
                    //F(i,mid,high_st) needed += k-a[i];
                    needed = ((ll)k)*(high_st - mid);
                    ll needsum = (high_st>0?psums[high_st-1]:0) - (mid>0?psums[mid-1]:0);
                    needed -= needsum;
                    check = available >= needed;
                }
                //printf("l %lld r %lld true mid %lld check %d\n",l,r,mid,check);
                //check=0;
                if(check) r=mid;
                else l=mid+1;
            }
            //cout<<l<<"\n";
            count = n-l;
            cout<<count<<"\n";
        }
    }
}


