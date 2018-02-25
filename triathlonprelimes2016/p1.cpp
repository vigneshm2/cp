#include<iostream>

using namespace std;

#define F(i,a,n) for(int i=(a);(i)<(n);(i)++)

int main(){
    int n;
    cin>>n;
    int xsum=0,x;
    F(i,0,n){
        cin>>x;
        xsum = xsum^x;
    }
    cout<<"Mr. "<<(xsum==0?"Y":"X")<<"\n";
}
