#include <cstdio>

int n;
int a[11], op[4];
int mx = -1e9, mn = 1e9;

void solve(int index, int ans, int add, int sub, int mul, int div) {
    if (index == n) {
        if (ans > mx) mx = ans;
        if (ans < mn) mn = ans;
        return;
    }
    if (add) solve(index+1, ans+a[index], add-1, sub, mul, div);
    if (sub) solve(index+1, ans-a[index], add, sub-1, mul, div);
    if (mul) solve(index+1, ans*a[index], add, sub, mul-1, div);
    if (div) solve(index+1, ans/a[index], add, sub, mul, div-1);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<4; i++) scanf("%d", &op[i]);
    solve(1, a[0], op[0], op[1], op[2], op[3]);
    printf("%d\n%d\n", mx, mn);
    return 0;
}
