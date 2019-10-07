#include <cstdio>

int tc, n;
long long sum, d[66][10];

int main() {
    for (int i = 0; i <= 9; i++) {
        d[1][i] = 1;
    }
    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                d[i][j] += d[i-1][k];
            }
        }
    }
    for (scanf("%d", &tc); tc--;) {
        scanf("%d", &n);
        for (int i = 0; i <= 9; i++) {
            sum += d[n][i];
        }
        printf("%lld\n", sum);
    }

    return 0;
}