#include <stdio.h>

int main()
{
    long long x, y;
    while(scanf("%lld %lld", &x, &y) != EOF)
    {
        int z = (long long)y * 100 / x;
        if(z >= 99) { printf("-1\n"); continue; }
        long long k = z+1;
        long long i = (x*k - 100*y - 1) / (100-k) + 1;
        printf("%lld\n", i);
    }
}
