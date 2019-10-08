#include <iostream> 
#define N_MAX 1000+1
#define DECI 10
#define DIV 10007
int main() { 
    int N; scanf("%d", &N);
    int dp[N_MAX][DECI] = { {0},{1,1,1,1,1,1,1,1,1,1} };
    for (int dp_idx = 2; dp_idx <= N; dp_idx++) 
        for (int deci_now = 0; deci_now < DECI; deci_now++) 
            for (int deci_bef = deci_now; deci_bef < DECI; deci_bef++) 
                dp[dp_idx][deci_now] += (dp[dp_idx - 1][deci_bef]%DIV);
 
    int ans = 0; 
    for (int deci_idx = 0; deci_idx < DECI; deci_idx++)
        ans += dp[N][deci_idx];
    printf("%d", ans%DIV);
    return 0;
}
