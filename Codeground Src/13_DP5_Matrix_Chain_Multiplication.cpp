#include <stdio.h>

int d[501][501], r[501], c[501];

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &r[i], &c[i]);
    }

    for(int l = 1; l < n; l++) {
        for(int i = 0; i < n - l; i++) {
            int j = i + l;
            d[i][j] = -1;
            for(int k = i; k < j; k++) {
                int calc = d[i][k] + d[k + 1][j] + r[i] * c[k] * c[j];
                if(d[i][j] < 0) {
                    d[i][j] = calc;
                } else if(calc < d[i][j]) {
                    d[i][j] = calc;
                }
            }
        }
    }

    printf("%d\n", d[0][n - 1]);
    return 0;
}