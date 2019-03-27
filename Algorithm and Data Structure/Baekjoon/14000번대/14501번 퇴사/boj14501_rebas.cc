#include <cstdio>

int n, ans;
int t[16], p[16];

void solve(int day, int profit) {
    if (day == n+1) {
        if (ans < profit) ans = profit;
        return;
    }
    if (day > n+1) return;
    solve(day+t[day], profit+p[day]);
    solve(day+1, profit);
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d %d", &t[i], &p[i]);
    solve(1, 0);
    printf("%d\n", ans);
    return 0;
}


