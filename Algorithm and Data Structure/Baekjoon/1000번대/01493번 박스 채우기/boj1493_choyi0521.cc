#include<stdio.h>
typedef long long ll;
int l, w, h, n, a[20], r;
ll b[21];
void f(int x, int y, int z) {
    if (!x || !y || !z) return;
    for (int i = 19, t; i >= 0; i--) {
        t = 1 << i;
        if (x / t && y / t && z / t) {
            b[i] += (ll)(x / t)*(y / t)*(z / t);
            for (int j = 1; j < 8; j++) f(j & 1 ? x%t : x / t*t, j & 2 ? y%t : y / t*t, j & 4 ? z%t : z / t*t);
            break;
        }
    }
}
int main() {
    scanf("%d %d %d %d", &l, &w, &h, &n);
    for (int i = 0, x, y; i < n; i++) scanf("%d %d", &x, &y), a[x] = y;
    f(l, w, h);
    for (int i = 19; i >= 0; i--) {
        b[i] += b[i + 1] * 8;
        ll t = a[i] > b[i] ? b[i] : a[i];
        b[i] -= t;
        r += t;
    }
    printf("%d", b[0] ? -1 : r);
    return 0;
}