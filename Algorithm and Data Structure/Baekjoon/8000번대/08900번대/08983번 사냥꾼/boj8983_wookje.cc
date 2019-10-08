#include <cstdio>
#include <algorithm>
using namespace std;

int m, n, l, ans, gun[100002];
pair<int, int> ani[100002];

int c(pair<int, int> p, int v) { return abs(p.first-v)+p.second; }

int main() {
    scanf("%d %d %d", &m, &n, &l);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &gun[i]);
    }
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d %d", &ani[i].first, &ani[i].second);
    }
    sort(gun+1, gun+m+1); sort(ani+1, ani+n+1);
    int p = 1;
    for (int i = 1; i <= n; i++) {
        while (p < m && gun[p+1] < ani[i].first) p++;
        p -= p==m;
        ans += min(c(ani[i], gun[p]), c(ani[i], gun[p+1])) <= l;
    }
    printf("%d\n", ans);
    return 0;
}