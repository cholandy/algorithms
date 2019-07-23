#include <cstdio>
 
int main() {
    int tcn;
    scanf("%d", &tcn);
    while (tcn--) {
        int a, b, c, d, i, x, y;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        b /= a;
        x = 0;
        for (i = b * d / c * d + b * d % c; i >= c; i = i / c * d + i % c) x += i / c;
        printf("%d\n", x);
    }
    return 0;
}