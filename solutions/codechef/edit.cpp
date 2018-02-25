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

vector<string> ops;
void op_del(string &s, int p){
    char c = s[p];
    string s1;
    for(char d: s){
        if(d!=c) s1.push_back(d);
    }
    s.clear();
    s.assign(all(s1));
    // printf("D %d\n",p);
    string o = "D " + to_string(p+1);
    ops.push_back(o);
}

void op_ins(string &s, int p, char c){
    if(p==s.size()) s.push_back(c);
    else s.insert(s.begin()+p, c);
    // printf("I %d %c\n",p,c);
    string o = "I "+to_string(p)+" "+c;
    ops.push_back(o);
}

void op_repl(string &s, int p, char c){
    s[p]=c;
    // printf("R %d %c\n",p,c);
    string o = "R "+to_string(p+1)+" "+c;
    ops.push_back(o);
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string t;
        cin>>t;
        int ic,lc,wc;
        cin>>ic>>lc>>wc;
        vvi rc(26,vi(26));
        F(i,0,26) F(j,0,26) cin>>rc[i][j];
        ops.clear();
        
        int cnt=0;
        while(s.length()>t.length()){
            op_del(s, 0);
            // cout<<s<<"\n"<<t<<"\n";
        }
        
        while(s.length()<t.length()){
            op_ins(s, s.size(), t[s.size()]);
            // cout<<s<<"\n"<<t<<"\n";
        }
        
        for(int i=0; i<s.length(); i++){
            if(s[i]!=t[i])
                op_repl(s, i, t[i]);
            // cout<<s<<"\n"<<t<<"\n";
        }
        
        cout<<ops.size()<<"\n";
        for(string op: ops){
            cout<<op<<"\n";
        }
    }
}


