#include <cstdio>

int n, b, c;
int a[1000000];
long ans;

void solve() {
    for (int i=0; i<n; i++) {
        if (a[i] >= b) {
            int d = a[i]-b;
            ans += (d%c == 0 ? d/c : d/c+1);
        }
    }
    printf("%lld\n", ans+n);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    scanf("%d %d", &b, &c);
    solve();
    return 0;
}

