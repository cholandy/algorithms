#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
char a[24];
int d[128];

void f(int i) {
    if (i == m + m) {
        puts(a);
        return;
    }
    a[i + 1] = 32;
    for (a[i] = 49; a[i] <= (n | 48); a[i]++) if (!d[a[i]]) {
        d[a[i]] = 1;
        f(i + 2);
        d[a[i]] = 0;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    f(0);
}