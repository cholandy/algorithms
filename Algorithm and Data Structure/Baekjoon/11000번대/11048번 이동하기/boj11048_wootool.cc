#include <stdio.h>
 
int candyMap[1001][1001];
int Dp[1001][1001];
 
int max(int a, int b)
{
    return a > b ? a : b;
}
 
int main(void){
 
    int N, M;
    scanf("%d %d", &N, &M);
 
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", &candyMap[i][j]);
 
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++){
            int result = 0;
            result =max(Dp[i-1][j-1],max(Dp[i - 1][j], Dp[i][j - 1]));
            Dp[i][j] = result + candyMap[i][j];
        }
 
 
    printf("%d\n", Dp[N][M]);
}


