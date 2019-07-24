#include <stdio.h>

int d[101][10001], v[101], w[101];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &v[i], &w[i]);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j < w[i]) {
                d[i][j] = d[i - 1][j];
            } else if(d[i - 1][j - w[i]] + v[i] > d[i - 1][j]) {
                d[i][j] = d[i - 1][j - w[i]]  + v[i];
            } else {
                d[i][j] = d[i - 1][j];
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= k; i++){
        if(ans < d[n][i]){
            ans = d[n][i];
        }
    }

    printf("%d\n", ans);
    return 0;
}