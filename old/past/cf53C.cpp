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
//    cout<<"0\n";
//    for(int i=0;i<4000;i++) cout<<"0";
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        if(i%2==0){
            cout<<i/2+1<<" ";
        } else {
            cout<<a-i/2<<" ";
        }
    }
    return 0;
}

