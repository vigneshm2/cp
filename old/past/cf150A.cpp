//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
const int INF = 1000000000;

int main(int argc, const char * argv[]) {
#ifdef local_test
//    freopen("input","w",stdout);
//    add input
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    ll q;
    cin>>q;
    if(q==1){
        cout<<"1\n0\n";
        return 0;
    }
    // prime/1 - win
    // product of 2 primes - loss
    // product of >2 primes - win
    ll p1=-1;
    for(ll i=2;i*i<=q;i++){
        if(q%i==0){
            p1=i;
            break;
        }
    }
    if(p1==-1){
        //prime
        cout<<"1\n0\n";
        return 0;
    }
    ll q1=q/p1;
    int p2=-1;
    for(ll i=2;i*i<=q1;i++){
        if(q1%i==0){
            p2=i;
            break;
        }
    }
    if(p2==-1){
        // prod of primes
        cout<<"2\n";
        return 0;
    }
    cout<<"1\n"<<p1*p2<<"\n";
    return 0;
}

