#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n, m, i, j, a[1502][1502], b[1502][1502], d[1502][1502];
char s[9];
int main() {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%s", s);
            (s[0]=='A' ? a[i][j] : b[i][j]) += atoi(s+1);
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            a[i][j] += a[i][j-1];
            b[i][m-j+1] += b[i][m-j+2];
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (i == 1 || j == 1) {
                d[i][j] = d[i-1][j] + b[i][j+1];
                continue;
            }
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j-1] + b[i][j+1];
            d[i][j] = max(d[i][j], d[i][j-1] - b[i][j] + b[i][j+1]);
        }
    }
    printf("%d\n", d[n][m]);
    return 0;
}