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
    freopen("input","w",stdout);
    cout<<"0\n";
    for(int i=0;i<4000;i++) cout<<"0";
//    add input
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int a;
    cin>>a;
    string s;
    cin>>s;
    vi num;
    for(int i=0;i<s.size();i++) num.push_back(s[i]-'0');
    int n=num.size();
    // sum(bi*bj) = sum(bi)*sum(bj);
    vi sums(n);
    sums[0]=num[0];for(int i=1;i<n;i++) sums[i]=sums[i-1]+num[i];
    vi subsums(9*n+10);
    for(int i=0;i<n;i++) for(int j=i;j<n;j++){
        if(i==0) subsums[sums[j]]++;
        else subsums[sums[j]-sums[i-1]]++;
    }
//    cout<<sums<<"\n";
//    for(int i=0;i<subsums.size();i++)
//        if(subsums[i]>0)
//            cout<<i<<" "<<subsums[i]<<"\n";
    ll count=0;
    if(a==0){
        for(ll i=0;i<=9*n;i++){
            count+=(ll)subsums[i]*subsums[0];
        }
        for(ll i=1;i<=9*n;i++){
            count+=(ll)subsums[0]*subsums[i];
        }
    } else {
        for(ll i=1;i<=9*n;i++){
            if(a%i==0 && a/i<=9*n){
                count+=(ll)subsums[i]*subsums[a/i];
            }
        }
    }
    cout<<count;
    return 0;
}

