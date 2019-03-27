#include <cstdio>
#include <algorithm>
int n, w, i, j, a[30003];
int main() {
    scanf("%d %d", &w, &n);
    for (; j<n; j++) scanf("%d", &a[j]);
    std::sort(a, a+n);
    for (j = n-1; j && i<j; j--) if (a[i]+a[j]<=w) i++;
    printf("%d", n-i);
    return 0;
}