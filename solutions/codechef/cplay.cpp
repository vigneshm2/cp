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

int check_over(int sa, int sb, int i, int &win){
    if(i<9){
        int lefta=(10-i-1)/2;
        int leftb=(10-i)/2;
        int maxa=sa+lefta, maxb=sb+leftb;
        //printf("%d: curr %d %d\n",i,sa,sb);
        //printf("%d: max %d %d\n",i,maxa,maxb);
        if(maxa < sb) {
            win=1;
            return 1;
        }
        if(maxb < sa) {
            win=0;
            return 1;
        }
    } else if (i==9){
        if(sa < sb) {
            win=1;
            return 1;
        } else if(sb < sa){
            win =0;
            return 1;
        }
    } else {
        if(i%2==1 && sa != sb){
            if(sa > sb) {
                win=0;
                return 1;
            } else {
                win=1;
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    string s;
    while(cin>>s){
        vi g(20);
        F(i,0,20) g[i]=s[i]-'0';

        int sa=0,sb=0,t=0,p=0,tie=1,win=-1;
        F(i,0,20){
            if(p==0) sa+=g[i];
            else sb+=g[i];
            if(check_over(sa,sb,i, win)){
                t=i+1;
                tie=0;
                break;
            }
            p=1-p;
        }
        if(!tie)
            if(win==0)
                cout<<"TEAM-A "<<t<<"\n";
            else
                cout<<"TEAM-B "<<t<<"\n";
        else 
            cout<<"TIE\n";
    }
}


