#include <iostream>

using namespace std;

#define F(i,a,n) for(int i=(a);i<(n);i++)
int poss[10];
int dp[100000];
const int INF=100000000;

int is_poss(int n){
    int c=0;
    while(n>0){
        if(!poss[n%10]) return 0;
        n/=10;
        c++;
    }
    return c;
}
int compute(int n){
    if(dp[n]>0) return dp[n];
    dp[n]=INF;
    int ps=is_poss(n);
    if(ps) dp[n]=min(dp[n],ps);
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            dp[n]=min(dp[n],compute(i)+1+compute(n/i));
        }
    }
    //cout<<"compute "<<n<<" = "<<dp[n]<<"\n";
    return dp[n];
}
int main(){
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        int c,d;
        F(i,0,10){
            cin>>c;
            poss[i]=c;
        }
        cin>>d;
        F(i,0,d+10) dp[i]=-1;
        int dd=compute(d);
        cout<<"Case #"<<tt<<": ";
        if(dd>=INF) cout<<"Impossible\n";
        else cout<<compute(d)+1<<"\n";
    }
}
