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
        int mv=110000;
        int n;
        cin>>n;
        vi a(n);
        cin>>a;
        vi b(a);

        if(n>5){
            map<int, int> cnt;
            F(i,0,n) cnt[a[i]]++;
            vi si(n),db(n);
            vi sis,dbs;
            F(i,0,n) if(cnt[a[i]]==1) {
                si[i]=1; 
                sis.pb(a[i]);
            }
            else if(cnt[a[i]]==2) {
                cnt[a[i]]=0;
                db[i]=1;
                dbs.pb(a[i]);
            }
            int nsi=sis.size(),ndb=dbs.size();
            map<int, int> bmap;
            nsi=sis.size(),ndb=dbs.size();

            F(i,0,nsi){
                bmap[sis[i]] = sis[(i+1)%nsi];
            }
            F(i,0,ndb){
                bmap[dbs[i]] = dbs[(i+1)%ndb];
            }
            

            //for(auto p: bmap) cout<<p<<"\n";

            int got_db1=0;
            F(i,0,n){
                b[i]=bmap[a[i]];
            }

            
            if(dbs.size() == 1){
                // swap 2 si with a db
                int si1id=-1,si2id=-1;
                int db1id=-1,db2id=-1;
                F(i,0,n){
                    if(a[i]==sis[0]) si1id=i;
                    else if(a[i]==sis[1]) si2id=i;
                    else if(a[i]==dbs[0]){
                        if(db1id==-1) db1id=i;
                        else db2id=i;
                    }
                }
                swap(b[si1id],b[db1id]);
                swap(b[si2id],b[db2id]);
            }
            if(sis.size() == 1){
                // swap 1 si with 1 db
                int si1id=-1;
                int db1id=-1;
                F(i,0,n){
                    if(a[i]==sis[0]) si1id=i;
                    else if(a[i]==dbs[0]){
                        db1id=i;
                    }
                }
                swap(b[si1id],b[db1id]);
            }
            
        } else {
            int maxh=-1; vi minb;
            b = a;
            sort(all(b));
            do{
                int h=0;
                F(i,0,n) h+=(a[i]!=b[i]);
                //cout<<h<<" "<<b<<"\n";
                if(h >maxh) {
                    minb=b;
                    maxh = h;
                }
            } while(next_permutation(all(b)));
            b = minb;
        }

        int h=0;
        F(i,0,n) h+=(a[i]!=b[i]);
        cout<<h<<"\n"<<b<<"\n";
    }
}

/*
 2,3 -> 1
 3,3 -> 3
 3,4 -> 2
 4,4 -> 4
 3,5 -> 1
 4,5 -> 3
 5,5 -> 5


 */


