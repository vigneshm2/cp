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

string compute(vi ad, string b, int n, int eq){
    //cout<<"compute: "<<ad<<"\n"<<"- "<<b<<" "<<n<<" "<<eq<<"\n";
    if(n==0) return "";
    if(eq){
        int m=b[0]-'0';
        if(ad[m]>0){
            ad[m]--;
            string nxt=compute(ad, b.substr(1), n-1, 1);
            if(nxt.size()>0 && nxt[0]=='-') ad[m]++;
            else{
                return string(1,b[0])+nxt;
            }
        }
        for(int i=m-1;i>=0;i--){
            if(ad[i]>0){
                ad[i]--;
                string nxt=compute(ad, b.substr(1), n-1, 0);
                if(nxt.size()>0 && nxt[0]=='-') ad[i]++;
                else{
                    return string(1,i+'0')+nxt;
                }
            }
        }
        return "-";
    } else {
        string na(n,'-');
        F(i,0,n){
            for(int j=9;j>=0;j--) if(ad[j]>0){
                ad[j]--;
                na[i]=j+'0';
                break;
            }
        }
        return na;
    }
}


int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    string a,b;
    cin>>a>>b;
    if(a.size() < b.size()){
        sort(all(a), greater<char>());
        cout<<a<<"\n";
    } else {
        int n=a.size();
        vi ad(10);
        F(i,0,n) ad[a[i]-'0']++;

        cout<<compute(ad, b, n, 1)<<"\n";
    }
}


