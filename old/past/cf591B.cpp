//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int INF = 1000000000;
const double PI =3.141592653589793238;
#pragma unused(INF,PI)
#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }


int main(int argc, const char * argv[]) {
#ifdef local_test
//    input
//    freopen("input","w",stdout);
//    cout<<"1 \n 100 10 \n";
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int change[26],ichange[26];
    F(i,0,26) change[i]=i,ichange[i]=i;
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    F(i,0,m){
        char a,b;
        scanf(" %c %c",&a,&b);
        int t1=ichange[a-'a'],t2=ichange[b-'a'];
        swap(change[t1],change[t2]);
        swap(ichange[a-'a'],ichange[b-'a']);
        //F(i,0,26) cout<<(char)(change[i]+'a')<<" ";cout<<"\n";
    }
    F(i,0,n){
        printf("%c",change[s[i]-'a']+'a');
    }
}

