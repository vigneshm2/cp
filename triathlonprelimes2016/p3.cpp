#include<iostream>
#include<stack>

using namespace std;

#define F(i,a,n) for(int i=(a);i<(n);i++)

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    stack<char> s;
    F(i,0,n){
        if(str[i]=='B'){
            int d=str[++i]-'0';
            F(j,0,d) s.pop();
        } else {
            s.push(str[i]);
        }
    }
    int x=0,y=0;
    while(!s.empty()){
        char c=s.top();s.pop();
        if(c=='L') x--;
        else if(c=='R') x++;
        else if(c=='U') y++;
        else if(c=='D') y--;
    }
    cout<<"("<<x<<","<<y<<")"<<"\n";
}


