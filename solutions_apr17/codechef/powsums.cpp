//  Created by Vignesh Manoharan

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

const int INF = 1000000000;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
const int mod=1000000007;
const double eps = 0.000001;

#define F(i,a,n) for(int i=(a);i<(n);i++)

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
    ll* e = (ll*)malloc(sizeof(ll)*n);
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
    matrix c = (ll*)malloc(sizeof(ll)*n*n);
    F(i,0,n) F(j,0,n) c[i*n+j]=0;
    F(i,0,n) F(j,0,n) F(k,0,n) c[i*n+j] = (c[i*n+j] + a[i*n+k]*b[k*n+j])%mod;
    return c;
}

ll* multiply_col(matrix a,ll* b){
    ll* c = (ll*)malloc(sizeof(ll)*n);
    F(i,0,n) c[i]=0;
    F(i,0,n) F(k,0,n) c[i] = (c[i] + a[i*n+k]*b[k])%mod;
    return c;
}
matrix unit(int n){
    matrix a = (ll*)malloc(sizeof(ll)*n*n);
    F(i,0,n) F(j,0,n) a[i*n+j]=(j==i);
    return a;
}
matrix exp_square(matrix a, int e){
    if(e==0) return unit(n);
    matrix sq = multiply_square(a,a);
    matrix eh = exp_square(sq,e/2);
    // printf("exp %d\n",e);
    free(sq);
    if(e%2==0) return eh;
    else return multiply_square(a,eh);
}
// void print_matrix(matrix a){
//     F(i,0,n) {F(j,0,n) cout<<a[i*n+j]<<" "; cout<<"\n";}
// }
// void print_col(ll* a){
//     F(i,0,n) cout<<a[i]<<"\n";
// }
matrix transition(ll* e, int n){
    matrix a = (ll*)malloc(sizeof(ll)*n*n);
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
    ll* f1 = (ll*)malloc(sizeof(ll)*n);
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
        free(tr_exp);
        return f1[0];
    }
}

void geninput(){
    int _n=300,_q=1;
    freopen("input", "w", stdout);
    printf("1\n%d %d\n",_n,_q);
    F(i,0,_n) printf("%d ",(modexp(2,i+1)+2)%mod);
    printf("\n");
    F(i,0,_q) printf("%d ",5000);
    printf("\n");
}
int main(int argc, const char * argv[]) {
    geninput();
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int t;
    scanf("%d",&t);
    while(t--){
        int q;
        scanf("%d%d",&n,&q);
        ll* f = (ll*)malloc(sizeof(ll)*n);
        F(i,0,n) scanf("%lld",f+i);
        ll* e = construct_e(f,n);
        // print_col(f);
        matrix tr = transition(e, n);
        // print_matrix(tr);
        free(e);
        F(i,0,q){
            ll k;
            scanf("%lld",&k);
            printf("%lld\n",find_f(tr,f,k));
        }
        free(f);
        free(tr);
    }
}
