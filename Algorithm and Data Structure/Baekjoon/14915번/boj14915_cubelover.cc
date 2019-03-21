#include <cstdio>

int main() {
    int n, m, t;
    scanf("%d%d", &n, &m);
    for (t = m; t <= n; t *= m);
    while (t /= m) printf("%X", n / t % m);
}