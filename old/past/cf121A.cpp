//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int INF = 1000000000;
#pragma unused(INF)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }

int main(int argc, const char * argv[]) {
#ifdef local_test
//    input
//    freopen("input","w",stdout);
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    vector<ll> luckynum;
    for(int i=1;i<10;i++){
        for(int j=0;j<(1<<i);j++){
            ll num=0;
            for(int k=0;k<i;k++){
                if(k>0) num*=10;
                if((1<<k) & j) num+=7;
                else num+=4;
            }
            luckynum.push_back(num);
        }
    }
    luckynum.push_back(4444444444ll);
    sort(luckynum.begin(),luckynum.end());
    int l,r;
    cin>>l>>r;
    ll sum=0;
    for(int i=0;i<luckynum.size();i++){
        ll num=luckynum[i];
        if(num<l) continue;
        if(num>r){
            if(i>0 && luckynum[i-1]>=r) break;
            if(i==0 || luckynum[i-1]<l) sum+=(r-l+1)*num;
            else sum+=(r-luckynum[i-1])*num;
        } else {
            if(i==0 || luckynum[i-1]<l) sum+=(num-l+1)*num;
            else sum+=(num-luckynum[i-1])*num;
        }
    }
    cout<<sum<<"\n";
//    ll sum2=0;
//    for(int i=l;i<=r;i++){
//        sum2+=*lower_bound(luckynum.begin(),luckynum.end(),i);
//    }
//    cout<<sum2;
    return 0;
}

