#include <stdio.h>
int map[1000][1000];
int primap[1000][1000];
 
int Max(int a, int b)
{
    return a > b ? a : b;
}
 
int main(void){
    
    int N, M;
 
    int line[2][1000];
 
    int total = 0;
 
    scanf("%d %d", &N, &M);
    // 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);
 
    primap[0][0] = map[0][0];
    for (int i = 1; i < M; i++)
    {
        primap[0][i] = primap[0][i - 1] + map[0][i];
    }
 
    for (int height = 1; height < N; height++)
    {
        // 한번 저장
        for (int row = 0; row < M; row++)
            line[0][row] = line[1][row] = primap[height - 1][row] + map[height][row];
 
        for (int row = 1; row < M; row++)
            line[0][row] = Max(line[0][row], line[0][row-1]+map[height][row]);
 
        for (int row = M-2; row >= 0; row--)
            line[1][row] = Max(line[1][row], line[1][row + 1] + map[height][row]);
 
        for (int row = 0; row < M; row++)
            primap[height][row] = Max(line[0][row], line[1][row]);
 
    }
    
    printf("%d\n", primap[N - 1][M - 1]);
 
    return 0;
}
