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
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

struct score{
    int index;
    vi played;
    string name;
    int point;
    int gd;
    int gf;
};
score new_score(string name, int n, int idx){
    return score{
        idx,
        vi(n),
        name,
        0,
        0,
        0
    };
}
ostream& operator<<(ostream &s,score sc){
    s<<sc.name<<"- points: "<<sc.point<<", gd: "<<sc.gd<<", gf: "<<sc.gf<<", played: "<<sc.played; return s;
}
bool score_sorter(const score &s1, const score &s2){
    if(s1.point>s2.point) return true;
    if(s1.point<s2.point) return false;
    if(s1.gd>s2.gd) return true;
    if(s1.gd<s2.gd) return false;
    if(s1.gf>s2.gf) return true;
    if(s1.gf<s2.gf) return false;
    string s1_u(s1.name), s2_u(s2.name);
    transform(all(s1_u),s1_u.begin(),::tolower);
    transform(all(s2_u),s2_u.begin(),::tolower);
    return s1_u.compare(s2_u)<0;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<string> names(n);
    F(i,0,n) cin>>names[i];
    map<string, int> dict;
    vector<score> scores(n);
    F(i,0,n){
        dict[names[i]] = i;
        scores[i] = new_score(names[i],n,i);
    }
    // cout<<names<<"\n";
    
    int m;
    cin>>m;
    int invalid=0;
    F(i,0,m){
        if(invalid) break;
        string n1,n2; int g1,g2;
        cin>>n1>>n2>>g1>>g2;
        if(n1==n2) invalid=1;
        int i1=dict[n1], i2=dict[n2];
        score *s1=&scores[i1], *s2=&scores[i2];
        if(g1>g2){
            //n1 win
            if(s1->played[i2]>=2) invalid=1;
            s1->point+=2;
            s1->played[i2]+=1;
            s1->gf+=g1;
            s1->gd+=g1-g2;
            
            if(s2->played[i1]>=2) invalid=1;
            s2->played[i1]+=1;
            s2->gf+=g2;
            s2->gd+=g2-g1;
        } else if(g1<g2){
            if(s1->played[i2]>=2) invalid=1;
            s1->played[i2]+=1;
            s1->gf+=g1;
            s1->gd+=g1-g2;
            
            if(s2->played[i1]>=2) invalid=1;
            s2->point+=2;
            s2->played[i1]+=1;
            s2->gf+=g2;
            s2->gd+=g2-g1;
        } else {
            if(s1->played[i2]>=2) invalid=1;
            s1->point+=1;
            s1->played[i2]+=1;
            s1->gf+=g1;
            
            if(s2->played[i1]>=2) invalid=1;
            s2->point+=1;
            s2->played[i1]+=1;
            s2->gf+=g2;
        }
    }
    if(invalid){
        cout<<"Invalid Input";
    } else {
        #ifdef LOCAL_TEST
        F(i,0,n) cout<<scores[i]<<"\n";
        #endif
        sort(all(scores), score_sorter);
        F(i,0,n) {
            cout<<scores[i].name;
            if(i<n-1) cout<<"\n";
        }
    }
    
}


