#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
char str[1002];
bool DP[1002][1002];
 
int main()
{
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++)
        DP[i][i] = true;
 
    for (int i = 1; i <= len - 1; i++)
        if (str[i] == str[i + 1])
            DP[i][i + 1] = true;
 
    // k칸 다음번째
    for (int k = 2; k <= len - 1; k++)
    {
        // 1부터 ~ n - k 번째 까지
        for (int i = 1; i <= len - k; i++)
        {
            // i + k번째 칸
            int j = i + k;
            if (str[i] == str[j] && DP[i + 1][j - 1])
                DP[i][j] = true;
        }
    }
 
    int val = -1;
    for (int i = 1; i <= len; i++)
        if (DP[i][len])
            val = max(val, len - i + 1);
 
    printf("%d", val + (len - val) * 2);
    return 0;
}