#include <cstdio>
int n, i, j, x, a[66][66] = {1};
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
        scanf("%d", &x);
        if (!a[i][j]) continue;
        if (i+x < n) a[i+x][j] = 1;
        if (j+x < n) a[i][j+x] = 1;
    }
    puts(a[n-1][n-1] ? "HaruHaru" : "Hing");
    return 0;
}