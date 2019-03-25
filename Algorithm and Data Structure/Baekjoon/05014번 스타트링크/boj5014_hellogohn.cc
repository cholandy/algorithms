#include <cstdio>
int main()
{
    int F, S, G, U, D, n;
    scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
    for (n = 0; n < 1000000; n++) {
        if (S == G) {
            printf("%d", n);
            return 0;
        }
        if (S + U > F && S - D < 1) break;
        if (S < G && S + U <= F) S += U;
        else if (!(S>G && S - D < 1)) S -= D;
    }
    puts("use the stairs");
}