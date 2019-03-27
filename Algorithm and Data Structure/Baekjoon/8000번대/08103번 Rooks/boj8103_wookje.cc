#include <cstdio>
#include <algorithm>
using namespace std;

int n, cx[3003], cy[3003];
struct abc {
    int s, e, idx;
    bool operator <(abc a)const {
        if (e == a.e) return s < a.s;
        return e < a.e;
    }
} x[3003], y[3003], r[3003];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &x[i].s, &y[i].s, &x[i].e, &y[i].e);
        x[i].idx = y[i].idx = i;
    }
    sort(x+1, x+n+1); sort(y+1, y+n+1);
    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (int j = 1; j <= n; j++) {
            if (!cx[j] && x[j].s <= i && i <= x[j].e) {
                cx[j] = r[x[j].idx].s = j;
                f++;
                break;
            }
        }
        for (int j = 1; j <= n; j++) {
            if (!cy[j] && y[j].s <= i && i <= y[j].e) {
                cy[j] = r[y[j].idx].e = j;
                f++;
                break;
            }
        }
        if (f != 2) {
            return !puts("NIE");
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", r[i].s, r[i].e);
    }
    return 0;
}