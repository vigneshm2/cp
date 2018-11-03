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

class BadNeighbors{
public:
    int maxDonations(vi);
    int compute(vi a){
        int n=(int)a.size();
        vi don(n);
        // don[0][0]=a[0],don[0][1]=0
        // don[x]=don[x-2]+a[x]
        for(int i=0;i<n;i++){
            if(i==0) don[i]=a[i];
            else if(i==1) don[i]=max(a[i],don[i-1]);
            else don[i]=max(don[i-2]+a[i],don[i-1]);
        }
        return don[n-1];
    }
};

int BadNeighbors::maxDonations(vi a){
    vi vf(a.begin()+1,a.end());
    vi vb(a.begin(),a.end()-1);
    return max(compute(vf,compute(vb)));
}
