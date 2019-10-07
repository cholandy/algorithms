#include <cstdio>
#include <algorithm>
int n, k, ans, a[100010], b[100010];
int main() {
    scanf("%d %d %d", &n, &k, &a[0]);
    for (int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        b[i-1] = a[i]-a[i-1];
    }
    std::sort(b, b+n-1);
    for (int i = 0; i < n-k; i++) {
        ans += b[i];
    }
    printf("%d", ans+k);
    return 0;
}