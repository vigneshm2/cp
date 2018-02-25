//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <numeric>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int INF = 1000000000;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
const int mod=1000000007;
const double eps = 0.000001;

#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){
    for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

typedef vector<vector<double>> matrix;
typedef vector<double> row;

void invert(matrix &a, int n, matrix &inv){
    vi piv(n),indxc(n),indxr(n);
    int irow,icol;
    F(i,0,n){
        double big=0.0;
        F(j,0,n){
            if(piv[j]!=1){
                F(k,0,n){
                    if(piv[k]==0){
                        if(fabs(a[j][k]>=big)){
                            big=fabs(a[j][k]);
                            irow=j;
                            icol=k;
                        }
                    }
                }
            }
        }
        ++(piv[icol]);
        if(irow!=icol){
            F(l,0,n) swap(a[irow][l],a[icol][l]);
        }
        indxr[i]=irow;
        indxc[i]=icol;
        // assert(a[icol][icol]!=0.0);
        double pivinv=1/a[icol][icol];
        a[icol][icol]=1.0;
        F(l,0,n) a[icol][l]*=pivinv;
        F(ll,0,n){
            if(ll!=icol){
                double dum=a[ll][icol];
                a[ll][icol]=0;
                F(l,0,n) a[ll][l]-=a[icol][l]*dum;
            }
        }
    }
    for(int l=n-1;l>=0;l--){
        if(indxr[l]!=indxc[l]){
            F(k,0,n){
                swap(a[k][indxr[l]],a[k][indxc[l]]);
            }
        }
    }
    // F(i,0,n) inv[i][i]=1;
    // F(i,0,n){
    //     // cout<<"a\n";
    //     // F(i,0,n) {F(j,0,n) printf("%.11lf ",a[i][j]); cout<<"\n";}
    //     // cout<<"\ninv\n";
    //     // F(i,0,n) {F(j,0,n) printf("%.11lf ",inv[i][j]); cout<<"\n";}
    //     // cout<<"\n\n";
    //     int j=i;
    //     while(a[j][j]==0) j++;
    //     F(k,0,n) a[i][k]+=a[j][k],inv[i][k]+=inv[j][k];
    //     double frac = 1.0/a[i][i];
    //     F(j,0,n) a[i][j]*=frac;
    //     F(j,0,n) inv[i][j]*=frac;
    //     F(j,0,n){
    //         if(j==i) continue;
    //         double frac = -a[j][i];
    //         //a[j]=a[j]+frac*a[i]
    //         F(k,0,n) {
    //             a[j][k]=a[j][k]+frac*a[i][k];
    //             inv[j][k]=inv[j][k]+frac*inv[i][k];
    //         }
    //     }
    // }
    F(i,0,n) F(j,0,n) a[i][j]=round(a[i][j]);
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n;
    cin>>n;
    matrix m(n,row(n));
    F(i,0,n) F(j,0,n) scanf("%lf",&m[i][j]);
    matrix inv(n,row(n));
    invert(m,n,inv);
    // F(i,0,n) {F(j,0,n) printf("%.11lf ",inv[i][j]); cout<<"\n";}
    string s(n*n,'a');
    // F(i,0,n) F(j,0,n) s[i+n*j]=inv[i][j]+'a'-1;
    F(i,0,n) F(j,0,n) s[i+n*j]=m[i][j]+'a'-1;
    // cout<<s;
    int end=n*n-1;
    for(int i=n*n-1;i>=(n-1)*(n-1);i--) {
        if(s[i]!=s[i-1]) {
            end=i;
            break;
        }
    }
    // cout<<end<<"\n";
    F(i,0,n*n-end){
        F(j,0,end+i+1) cout<<s[j];
        if(i!=n*n-end-1) cout<<" ";
    }
}


