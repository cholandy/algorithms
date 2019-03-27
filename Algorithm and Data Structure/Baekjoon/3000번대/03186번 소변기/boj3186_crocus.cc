#include <iostream>
#include <cstdio>
 
using namespace std;
 
bool arr[10002];
 
int main()
{
    int k, l, n;
    scanf("%d %d %d", &k, &l, &n);
 
    for (int i = 1; i <= n; i++)
        scanf("%1d", &arr[i]);
 
    bool use = false;
    int useTime = 0;
    bool flush = false;
    int flushTime = 0;
 
    for (int i = 1; i <= n; i++)
    {
        if (arr[i])
        {
            useTime++;
            if (useTime >= k)
                use = true;
            flushTime = 0;
        }
 
        else
        {
            if (use)
            {
                flushTime++;
                if (flushTime >= l)
                {
                    printf("%d\n", i);
                    flush = true;
                    use = false;
 
                    flushTime = 0;
                }
            }
 
            useTime = 0;
        }
    }
 
    if (use)
    {
        printf("%d\n", l + n - flushTime);
        flush = true;
    }
 
    if (!flush)
        printf("NIKAD\n");
 
    return 0;
}ntf("%d\n", maxVal);
    printf("%d\n", minVal);
    return 0;
}
