
#include <cstdio>
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

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

struct stat{
	int r,p,s;
};	
ostream& operator<< (ostream& out,const stat s){
	out<<"{r="<<s.r<<",p="<<s.p<<",s="<<s.s<<"}";
	return out;
}
stat add(stat init,char code){
	switch(code){
		case 'R':
			init.p++;
			return init;
		case 'P':
			init.s++;
			return init;
		case 'S':
			init.r++;
			return init;
	}
	return init;
}
int score(stat s1,stat s2,stat s3,bool opp){
	if(opp)
		return s1.s+(s2.r-s1.r)+(s3.p-s2.p);
	else
		return s1.p+(s2.s-s1.s)+(s3.r-s2.r);	
}
void run(){
	tests{
		si(n);
		vector<stat> stats;
		string s;
		cin>>s;
		dbg(s);
		F(i,0,n){
			dbg(s[i]);
			if(i==0){
				stats.pb({.r=0,.p=0,.s=0});
				stats[i]=add(stats[i],s[i]);
			} else {
				stats.pb(add(stats[i-1],s[i]));
			}
		}
		int count=0;
		F(i,0,n) F(j,i,n){
			int sm=score(stats[i],stats[j],stats[n-1],true),sy=score(stats[i],stats[j],stats[n-1],false);
			dbg(i);dbg(j);
			dbg(sm);dbg(sy);
			if(sm>sy){
				count++;
			}
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
