#include <iostream>
#include <cstdio>
#include <string.h>
 
using namespace std;
 
const long long MOD = 1000000;
 
long long dp[5003];
char str[5003];
 
int main()
{
        scanf("%s", str + 1);
 
        int len = strlen(str + 1);
 
        if (str[1] == '0')
        {
            printf("0");
            return 0;
        }
 
        dp[0] = dp[1] = 1;
 
        for (int i = 2; i <= len; i++)
        {
            if (str[i] != '0')
                dp[i] = dp[i - 1] % MOD;
 
            if(str[i - 1] == '1' || str[i - 1] == '2' && str[i] <= '6')
                dp[i] += dp[i - 2] % MOD;
        }
 
        printf("%lld\n", dp[len] % MOD);
 
    return 0;
}