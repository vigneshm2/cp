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

int score_boxes(vi types, int num){
    if(num<4) return 0;
    if(types.size()<num) return score_boxes(types,num-1);
    int minv=INF;
    F(i,0,types.size()) minv=min(minv,types[i]);
    int curr=0;
    if(num==6) curr+=minv*4;
    else if(num==5) curr+=minv*2;
    else curr+=minv;
    vi t2;
    F(i,0,6) if(types[i]-minv>0) t2.pb(types[i]-minv);
    int score=curr+score_boxes(t2,num-1);
    cout<<"score_boxes of "<<types<<" , "<<num<<" = "<<score<<"\n";
    return score;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    F(tt,0,t){
        int n;
        cin>>n;
        vi score(n);
        F(i,0,n){
            int k;
            cin>>k;
            vi type(6);
            F(i,0,k){
                int c;
                cin>>c;
                type[c-1]++;
            }
            // int ntypes=0;
            // F(i,0,6) ntypes+=type[i];
            score[i]=k+score_boxes(type,6);
            // if(ntypes==4) score[i]+=1;
            // else if(ntypes==5) score[i]+=2;
            // else if(ntypes==6) score[i]+=4;
        }
        cout<<score<<"\n";
        int maxscore=-1;
        F(i,0,n) maxscore=max(maxscore,score[i]);
        int nmax=0,winner=-1;
        F(i,0,n) if(score[i]==maxscore) nmax++,winner=i;
        if(nmax!=1) cout<<"tie\n";
        else if(winner==0) cout<<"chef\n";
        else cout<<winner+1<<"\n";
    }
}


