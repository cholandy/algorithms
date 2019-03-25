#include<cstdio>
int n, m, s[100001];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", s + i), s[i] += s[i - 1];
    for (int i = 0, x, y; i < m; i++) {
        scanf("%d%d", &x, &y);
        printf("%d\n", s[y] - s[x - 1]);
    }
    return 0;
}