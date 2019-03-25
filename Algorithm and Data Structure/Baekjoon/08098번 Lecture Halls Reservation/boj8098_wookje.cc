#include <cstdio>
#include <algorithm>
using namespace std;
int n, r, d[30003];
pair<int, int> a[10002];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].second, &a[i].first);
    }
    sort(a, a+n);
    int i = 0, t = 1;
    while (t <= 30000) {
        int x = a[i].second, y = a[i].first;
        d[t] = max(d[t], d[t-1]);
        if (y > t || i == n) {
            t++;
            continue;
        }
        d[t] = max(d[t], d[x]+y-x);
        if (i < n) i++;
    }
    printf("%d", d[t-1]);
    return 0;
}