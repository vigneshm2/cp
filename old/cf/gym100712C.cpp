
#include <cstdio>
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>

using namespace std;

#ifdef DEBUG
#define dbg(x)  cerr << #x << " : "<< (x) << '\n';
#define pr(x) cout << (x);
#else
#define dbg(x)  ;
#define pr(x) ;
#endif
#define F(i,initial,limit) for(int i=(initial);i<(limit);i++)
#define FV(i,v) for(auto i=(v).begin();i<(v).end();++i)
#define FV2(i,initial,limit) for(auto i=initial,j=limit;i!=j;++i)
#define si(x) int (x);scanf("%d",&(x));
#define si2(x,y) int (x),(y); scanf("%d%d",&(x),&(y));
#define tests si(TESTS);while(TESTS--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(),v.end()

template <typename T,typename S>
ostream& operator<< (ostream& out, const pair<T,S>& p) {
  out<<'('<<p.first<<','<<p.second<<')';
  return out;
}
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out<<'[';
  for(auto it=v.begin();it!=v.end();++it)
		if(it!=--v.end())
			out<<*it<<",";
		else
			out<<*it;
	out<<']';
  return out;
}
template <typename T,typename S>
ostream& operator<< (ostream& out, const map<T,S>& v) {
	out<<'[';
  for(auto it=v.begin();it!=v.end();++it)
		if(it!=--v.end())
			out<<it->first<<":"<<it->second<<",";
		else
			out<<it->first<<":"<<it->second;
	out<<']';
  return out;
}


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<vi> vvi;

void run(){
	tests{
		string s;
		cin>>s;
		int count=0;
		char* part=strtok(s.c_str(),"*");
		while(part!=NULL){
			count+=strlen(part)/3;
			part=strtok(NULL,"*");
		}
		cout<<count<<'\n';
	}
}

int main(int argc, char const *argv[]) {
	#ifdef DEBUG
	 	freopen("input","r",stdin);
		freopen("output","w",stdout);
		ll start=clock();
	#endif
	run();
	#ifdef DEBUG
		ll stop=clock();
		cout<<"\ntime "<<(stop-start)/1000.0<<"\n";
	#endif
	return 0;
}
