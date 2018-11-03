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

class Trie{
public:
    struct node{
        int is_end = 0;
        int is_good_end = 0;
        int is_bad_end = 0;
        int bad = 0;
        string pref;
        vector<node*> children = vector<node*>(26, NULL);
    };
    node* root;
    int debug;
    vector<string> ans;

    Trie(int dbg=0){
        root = new node;
        debug = dbg;
        if(debug) root->pref="";
    }

    void insert(string s, int bad = 0){
        node* n = root;
        F(i,0,s.size()){
            int c = ord(s[i]);
            if(!n->children[c]){
                n->children[c] = new node;
                if(debug) n->children[c]->pref = n->pref + chr(c);
            }
            if(bad) n->bad=1;
            n = n->children[c];
        }
        if(bad) n->bad=1;
        n->is_end = 1;
        if(bad) n->is_bad_end = 1;
        else n->is_good_end = 1;
    }

    int reqprefs(node* n){
        if(!n->bad) {
            if(debug) ans.push_back(n->pref);
            //cout<<n->pref<<"\n";
            return 1;
        }
        if(n->is_good_end && n->bad){
            return -1;
        }
        int c=0,tot=0;
        F(i,0,26){
            c=0;
            if(n->children[i]) c=reqprefs(n->children[i]);
            if(c==-1) return -1;
            tot+=c;

        }
        return tot;
    }

    int reqprefs(){
        return reqprefs(root);
    }

    int pref_len(string s){
        // find max prefix of s in the trie
        node* n = root;
        int count=0;
        F(i,0,s.size()){
            int c = ord(s[i]);
            if(!n->children[c])
                return count;
            count++;
            n = n->children[c];
        }
        return count;
        return 0;
    }

private:
    int ord(char c){
        // 'a'-'z' to 0-25
        return c-'a';
    }
    char chr(int c){
        return c+'a';
    }

};

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    Trie t(1);
    int n;
    cin>>n;
    vector<string> strs;
    F(i,0,n){
        char c;string s;
        strs.pb(s);
        cin>>c>>s;
        t.insert(s, (c=='+'));
    }
    t.ans.clear();
    int n_req = t.reqprefs();
    cout<<n_req<<"\n";
    if(n_req > 0)
        for(string s: t.ans) cout<<s<<"\n";
}


