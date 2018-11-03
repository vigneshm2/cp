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
    int n,l,r,ql,qr;
    cin>>n>>l>>r>>ql>>qr;
    if(n==0){
        cout<<"err";
        return 0;
    }
    vi w(n);
    for(int i=0;i<n;i++) cin>>w[i];
    vi lsums(n);
    lsums[0]=w[0];for(int i=1;i<n;i++) lsums[i]=lsums[i-1]+w[i];
    int mscore=INF;
    for(int nl=0;nl<=n;nl++){
        int nr=n-nl;
        int score;
        if(nl>nr){
            int rep=nl-nr-1;
            score=l*((nl>0)?lsums[nl-1]:0)+r*(lsums[n-1]-((nl>0)?(lsums[nl-1]):0))+rep*ql;
        } else if(nl<nr){
            int rep=nr-nl-1;
            score=l*((nl>0)?lsums[nl-1]:0)+r*(lsums[n-1]-((nl>0)?(lsums[nl-1]):0))+rep*qr;
        } else {
            score=l*((nl>0)?lsums[nl-1]:0)+r*(lsums[n-1]-((nl>0)?(lsums[nl-1]):0));
        }
        if(mscore>score) mscore=score;
    }
    cout<<mscore;
    return 0;
}

