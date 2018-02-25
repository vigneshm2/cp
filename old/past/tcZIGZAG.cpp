//  Created by Vignesh M

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <stack>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int INF = 1000000000;
const double PI =3.141592653589793238;

class ZigZag{
public:
    int longestZigZag(vi);
};

int ZigZag::longestZigZag(vi a){
    int n=(int)a.size();
    vector<vi> zig(n,vi(2,1));
    // zig[i]=max(zig[j]+1) , j<i & a[j]>/<a[i]
    // zig[i][0]=max(zig[j][1]+1) a[j]>a[i]
    // zig[i][1]=max(zig[j][0]+1) a[j]<a[i]
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]<a[j]){
                zig[i][0]=max(zig[i][0],zig[j][1]+1);
            }
            if(a[i]>a[j]){
                zig[i][1]=max(zig[i][1],zig[j][0]+1);
            }
        }
    }
    int lmax=1;
    for(int i=0;i<n;i++) lmax=max(lmax,max(zig[i][0],zig[i][1]));
    return lmax;
}
