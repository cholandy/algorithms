#include <cstdio>
int n, i, j, k, f, a[202][202];
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++)
        scanf("%d", &a[i][j]);
    for (i = 0; i < n; i++) for (j = i+1; j < n; j++) {
        f = 0;
        for (k = 0; k < n; k++) {
            if (i == k or j == k) continue;
            if (a[i][j] == a[i][k] + a[k][j]) f = 1;
        }
        if (!f) printf("%d %d\n", i+1, j+1);
    }
    return 0;
}