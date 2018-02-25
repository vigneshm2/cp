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
#include <unordered_set>

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

struct game{
    int r, minr, maxr, time;
    int rated, color; // 0-w, 1-b, 2-random
    int id;
};

int isok(game g1, game g2){
    //g2 trying to join g1
    if(g1.r < g2.minr || g1.r>g2.maxr) return 0;
    if(g2.r < g1.minr || g2.r>g1.maxr) return 0;
    if(g1.time != g2.time || g1.rated != g2.rated) return 0;
    if(g1.color +g2.color ==1) return 1;
    if(g1.color + g2.color == 4) return 1;
    return 0;

}
namespace std {
    template<>
    struct hash<game> {
        inline size_t operator()(const game& g) const {
            return (size_t)g.id;
        }
    };
    template<>
    struct equal_to<game> {
        inline bool operator()(const game& g, const game& g1) const {
            return g.id == g1.id;
        }
    };
}
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
        unordered_set<game> s;
        F(i,0,n){
            game g;
            cin>>g.r>>g.minr>>g.maxr>>g.time;
            string rat,col;
            cin>>rat>>col;
            g.rated = (rat=="rated");
            if(col=="white") g.color=0;
            else if(col=="black") g.color=1;
            else g.color=2;
            g.id =i+1;

            int got=0;
            game gotg;gotg.id=INF;
            for(game g1: s){
                if(isok(g1, g)){
                    if(got!=0){
                        if(g1.id > gotg.id) continue;
                    }
                   got =1;
                   gotg=g1;
                } 
            }
            if(!got){
                s.insert(g);
                cout<<"wait\n";
            } else {
                   s.erase(gotg);
                   cout<<gotg.id<<"\n";
            }
        }
    }
}


