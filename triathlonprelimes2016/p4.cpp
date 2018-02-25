#include <iostream>

using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    if(a>b) swap(a,b);
    for(int i=(n-1)*a;i<=(n-1)*b;i+=(b-a)){
        cout<<i<<" ";
    }
}
