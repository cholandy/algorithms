#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
char a[24];

void f(int i) {
    if (i == m + m) {
        puts(a);
        return;
    }
    for (int j = 49; j < n; j++) {
        a[i] = j;
        f(i + 2);
    }
}

int main() {
    int i;
    scanf("%d%d", &n, &m);
    n += 49;
    for (i = 0; i < m + m - 1; i++) a[i] = 32;
    f(0);
}