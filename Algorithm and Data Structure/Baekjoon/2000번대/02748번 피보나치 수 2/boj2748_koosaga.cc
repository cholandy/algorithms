#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef long long lint;

struct matrix{lint a[2][2];};
lint mod = 5e18;
lint n;

matrix operator*(matrix a, matrix b){
    matrix c;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            c.a[i][j] = 0;
            for (int k=0; k<2; k++) {
                c.a[i][j] += a.a[i][k] * b.a[k][j];
                c.a[i][j] %= mod;
            }
        }
    }
    return c;
}

matrix base(){
    matrix c;
    memset(c.a,0,sizeof(c.a));
    c.a[1][0] = c.a[0][1] = c.a[0][0] = 1;
    return c;
}

matrix E(){
    matrix x;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            x.a[i][j] = (i == j);
        }
    }
    return x;
}

void input(){
    scanf("%lld",&n);
    if(n == 1){
        puts("1");
        exit(0);
    }
    n--;
}

int main(){
    input();
    matrix res = E(), piv = base();
    while (n) {
        if(n&1) res = res * piv;
        piv = piv * piv;
        n >>= 1;
    }
    printf("%lld",res.a[0][0]);
}