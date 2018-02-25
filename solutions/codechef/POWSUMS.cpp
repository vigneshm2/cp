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
typedef vector<ll> vll;
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

int n;
typedef ll* matrix;

ll modexp(ll a,int e){
    if(e==0) return 1ll;
    ll sq=modexp(a,e/2);
    if(e%2==0) return (sq*sq)%mod;
    else return a*(sq*sq%mod)%mod;
}
ll modinv(ll a){
    return modexp(a,mod-2);
}
ll* construct_e(ll *f, int n){
    // i*e_i=e_i-1 p_1 - e_i-2 p_2 + .... (-1)^i p_i
    // e[0] = f[0]
    // e[1] = e[0]f[0] - f[1] /2
    // e[2] = e[1]f[0] - e[0]f[1] + f[2] /3
    ll* e = new ll[n];
    F(i,0,n){
        e[i]=0;
        ll prod=1;
        for(int j=i-1;j>=0;j--){
            e[i] = (e[i] + mod + (prod*e[j]*f[i-j-1])%mod)%mod;
            prod=-prod;
        }
        e[i] = (e[i] + mod + prod*f[i])%mod;
        e[i] = (e[i] * modinv(i+1))%mod;
    }
    return e;
}
matrix multiply_square(matrix a,matrix b){
    matrix c = new ll[n*n];
    F(i,0,n) F(j,0,n) c[i*n+j]=0;
    F(i,0,n) F(j,0,n) F(k,0,n) c[i*n+j] = (c[i*n+j] + a[i*n+k]*b[k*n+j])%mod;
    return c;   
}

ll* multiply_col(matrix a,ll* b){
    ll* c = new ll[n];
    F(i,0,n) c[i]=0;
    F(i,0,n) F(k,0,n) c[i] = (c[i] + a[i*n+k]*b[k])%mod;
    return c;
}
matrix unit(int n){
    matrix a = new ll[n*n];
    F(i,0,n) F(j,0,n) a[i*n+j]=(j==i);
    return a;
}
matrix exp_square(matrix a, int e){
    if(e==0) return unit(n);
    matrix sq = multiply_square(a,a);
    matrix eh = exp_square(sq,e/2);
    printf("trying exp %d\n",e);
    delete[] sq;
    if(e%2==0) return eh;
    else return multiply_square(a,eh);
}
void print_matrix(matrix a){
    F(i,0,n) {F(j,0,n) cout<<a[i*n+j]<<" "; cout<<"\n";}
}
void print_col(ll* a){
    F(i,0,n) cout<<a[i]<<"\n";
}
matrix transition(ll* e, int n){
    matrix a = new ll[n*n];
    int prod=1;
    F(i,0,n){
        a[i] = (mod + prod*e[i])%mod; //a[0*n+i]
        prod = -prod;
    }
    F(i,1,n){
        F(j,0,n) a[i*n+j] = (j == i-1);
    }
    return a;
}
ll* init_f(ll* f){
    ll* f1 = new ll[n];
    F(i,0,n) f1[i] = f[n-1-i];
    return f1;
}
ll find_f(matrix tr,ll *f,ll q){
    // find f[q-1]
    // f[i]=e[0]*f[i-1]-e[1]*f[i-2]+e[2]*f[i-3]+...e[n-1]*f[i-n]
    if(q-1<n) return f[q-1];
    else {
        ll* f1 = init_f(f);
        // F(i,n,q){
        //     f1 = multiply_col(tr, f1, n);
        // }
        matrix tr_exp=exp_square(tr,q-n);
        f1 = multiply_col(tr_exp,f1);
        delete[] tr_exp;
        return f1[0];
    }
}

int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    // freopen("input","w",stdout);
    //     int _n=300,_q=30;
    //     printf("1\n%d %d\n",_n,_q);
    //     F(i,0,_n) printf("%lld ",(modexp(2,i+1)+2)%mod);
    //     printf("\n");
    //     F(i,0,_q) printf("5000 ");
    //     printf("\n");
    // freopen("output", "w", stdout);
    freopen("input", "r", stdin);
    #endif
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>n>>q;
        ll* f = new ll[n];
        F(i,0,n) cin>>f[i];
        ll* e = construct_e(f,n);
        // print_col(f);
        matrix tr = transition(e, n);
        // print_matrix(tr);
        delete[] e;
        F(i,0,q){
            ll k;
            cin>>k;
            cout<<find_f(tr,f,k)<<"\n";
        }
        delete[] f;
        delete[] tr;
    }
}


