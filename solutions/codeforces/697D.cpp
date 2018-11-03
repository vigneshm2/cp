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
vvi graph;
vi size;
vector<double> times;
int find_size(int i){
    int sz=1;
    for(int v:graph[i]) sz+=find_size(v);
    return size[i]=sz;
}
double find_time(int i){
    // sets times for all children
    int tot=size[i]-1;
    double cur_times=times[i];
    for(int v: graph[i]){
        times[v] = (tot-size[v])/2.0+cur_times+1.0;
        find_time(v);
    }
    return times[i];
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    
    cin>>n;
    graph=vvi(n, vi());
    F(i,0,n-1){
        int p;
        cin>>p;
        graph[p-1].pb(i+1); // p -> i+2
    }
    size=vi(n); //number of nodes in subtree
    times=vector<double>(n);
    find_size(0);
    times[0]=1.0;
    find_time(0);
    // cout<<size<<"\n";
    cout<<times<<"\n";
}


