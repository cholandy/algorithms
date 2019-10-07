#include <stdio.h>
 
int main()
{
    int tc = 1;
    while (1)
    {
        int l, p, v;
        scanf("%d %d %d", &l, &p, &v);
 
        if (l == 0 && p == 0 && v == 0)
            break;
 
        if (v % p <= l)
            printf("Case %d: %d\n", tc++, (v / p)*l + v % p);
        else
            printf("Case %d: %d\n", tc++, (v / p)*l + l);
    }
    return 0;
}
 