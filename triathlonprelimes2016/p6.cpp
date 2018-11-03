#include <iostream>

using namespace std;

#define F(i,a,n) for(int i=(a);i<(n);i++)

int main(){
    int graph[26][26];
    int dist[26][26];
    F(i,0,26) F(j,0,26) {
        cin>>graph[i][j];
        dist[i][j]=graph[i][j];
    }
    F(k,0,26) F(i,0,26) F(j,0,26) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    string s1,s2;
    cin>>s1>>s2;
    int cost=0;
    F(i,0,s1.size()) cost+=dist[s1[i]-'a'][s2[i]-'a'];
    cout<<cost<<"\n";
}
