#include <cstdio>
#include <algorithm>

int n, a[1001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    std::sort(a, a+n);

    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mx+1) {
            break;
        }
        mx += a[i];
    }

    printf("%d\n", mx+1);

    return 0;
}