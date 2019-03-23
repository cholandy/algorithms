#include <iostream>
#include <cstdio>
 
using namespace std;
 
int dp[303][303][13];
int arr[303][303];
 
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d",&arr[i][j]);
 
    for(int i = 1 ; i <= n ; i++)
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= 10; k++)
            {
                dp[i][j][k] += dp[i][j - 1][k];
                dp[i][j][k] += dp[i - 1][j][k];
                dp[i][j][k] -= dp[i - 1][j - 1][k];
            }
 
            dp[i][j][arr[i][j]]++;
        }
 
    int q;
    scanf("%d", &q);
 
    while (q--)
    {
        int x1, y1, x2, y2, cnt = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
 
        int tmp[11];
        for (int i = 1; i <= 10; i++)
            tmp[i] = dp[x2][y2][i];
 
        for (int i = 1; i <= 10; i++)
        {
            tmp[i] -= dp[x1 - 1][y2][i];
            tmp[i] -= dp[x2][y1 - 1][i];
            tmp[i] += dp[x1 - 1][y1 - 1][i];
        }
 
        for (int i = 1; i <= 10; i++)
            if(tmp[i] > 0)
                cnt++;
 
        printf("%d\n", cnt);
    }
 
    return 0;
}
