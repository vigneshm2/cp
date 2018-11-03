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
typedef vector<vii> vvii;

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

vi parent;
vi vrank;
vi opp;

void make_set (int v) {
	parent[v] = v;
	vrank[v] = 0;
	opp[v] = -1;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}


int d_union_sets (int a, int b, int rec=1) {
    // merge a,b and opp[a],opp[b]
    // cout<<"merging "<<a<<" "<<b<<"\n";
    
	if (a != b) {
		if (vrank[a] < vrank[b])
			swap (a, b);
		parent[b] = a;
		if(opp[b]!=-1 && rec){
		    if(opp[a]==-1) opp[a]=find_set(opp[b]);
		    else{
		        opp[a]=d_union_sets(find_set(opp[a]),find_set(opp[b]),0);
		    }
		}
		if (vrank[a] == vrank[b])
			++vrank[a];
	}
	return a;
}
int d_opp_sets (int a, int b) {
    // merge a,opp[b] and b,opp[a]
    
    if(opp[b]!=-1){
        opp[b]=d_union_sets(a,find_set(opp[b]));
    } else {
        opp[b]=a;
    }
    
    if(opp[a]!=-1){
        opp[a]=d_union_sets(b,find_set(opp[a]));
    } else {
        opp[a]=b;
    }
    return 0;
}
int union_sets (int a, int b){
    return d_union_sets(find_set (a),find_set (b));
}
int opp_sets(int a, int b){
    return d_opp_sets(find_set (a),find_set (b));
}
int isopp(int a, int b){
    a=find_set(a);
    b=find_set(b);
    return a==find_set(opp[b]);
}
int issame(int a, int b){
    a=find_set(a);
    b=find_set(b);
    return a==b;
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n,m,q;
    cin>>n>>m>>q;
    vector<string> names(n);
    cin>>names;
    map<string, int> nmap;
    F(i,0,n) nmap[names[i]]=i;
    
    vrank.resize(n);
    parent.resize(n);
    opp.resize(n);
    F(i,0,n) make_set(i);
    
    F(i,0,m){
        // F(i,0,n) cout<<find_set(i)<<" "; cout<<"\n";
        // F(i,0,n) cout<<opp[find_set(i)]<<" "; cout<<"\n";
        int type;
        string a,b;
        cin>>type>>a>>b;
        int u=nmap[a],v=nmap[b];
        if(type==1){
            if(!isopp(u,v)){
                union_sets(u,v);
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        } else {
            if(!issame(u,v)){
                // if(v!=0)
                opp_sets(u,v);
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
        
    }
    // F(i,0,n) cout<<find_set(i)<<" "; cout<<"\n";
    // F(i,0,n) cout<<opp[find_set(i)]<<" "; cout<<"\n";
    F(i,0,q){
        string a,b;
        cin>>a>>b;
        int u=nmap[a],v=nmap[b];
        if(issame(u,v)){
            cout<<"1\n";
        } else if(isopp(u,v)){
            cout<<"2\n";
        } else {
            cout<<"3\n";
        }
    }
    
}


