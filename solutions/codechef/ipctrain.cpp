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
typedef tuple<int,int,int> iii;
typedef vector<iii> viii;

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

int start(iii t){
    return get<0>(t);
}
int sad(iii t){
    return get<1>(t);
}
int ntasks(iii t){
    return get<2>(t);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        
        viii trainers(n); // (start, sadness, count)
        F(i,0,n){
            int d,ti,s;
            cin>>d>>ti>>s;
            trainers[i] = iii(d, s, ti);
        }

        sort(all(trainers));

        //F(i,0,n){
            //int d,ti,s;
            //tie(d,s,ti) = trainers[i];
            //printf("%d %d %d\n",d,s,ti);
        //}
        int trainer_idx = 0;
        iii curr_trainer = trainers[trainer_idx];
        vi n_done(d);
        priority_queue<ii> pq;

        F(i,1,d+1){
            // add all active trainers
            //cout<<"day "<<i<<"\n";
            while(start(curr_trainer) <= i){
                //cout<<"adding idx "<<trainer_idx<<"\n";
                pq.push(ii(sad(curr_trainer), trainer_idx));
                if(trainer_idx == n-1) {
                    curr_trainer = iii(INF,0,0);
                } else {
                    curr_trainer = trainers[++trainer_idx];
                }
            }
            // pick top
            if(!pq.empty()){
                ii chosen = pq.top();
                int chosen_idx = chosen.second;
                //cout<<"top "<<chosen_idx<<"\n";
                n_done[chosen_idx]++;
                if(n_done[chosen_idx] == ntasks(trainers[chosen_idx])){
                    // remove
                    //cout<<"removing "<<chosen_idx<<"\n";
                    pq.pop();   
                }
            }
        }

        ll tot_sad = 0;
        F(i,0,n){
            iii tr = trainers[i];
            tot_sad += sad(tr)*(ntasks(tr)-n_done[i]);
        }
        cout<<tot_sad<<"\n";
    }
}


