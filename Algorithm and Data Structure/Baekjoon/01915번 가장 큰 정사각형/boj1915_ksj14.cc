#include <stdio.h>
 
int map[1001][1001];
int sum[1001][1001];
int n, m;
 
int max(int first, int second) {
    if (first > second)    return first;
    return second;
}
 
int search()
{
    int y, x;
    int mx = 0;
    int length = 0, space;
 
    for (y = 1; y + length <= n; y++) {
        for (x = 1; x + length <= m; x++) {
            if (!map[y][x] || !map[y + length][x + length])    continue;
    
            space = sum[y + length][x + length] - sum[y - 1][x + length] 
                    - sum[y + length][x - 1] + sum[y - 1][x - 1];
 
            while (space == ((length + 1) * (length + 1))) {
                if (space > mx)    mx = space;
                length++;
                space = sum[y + length][x + length] - sum[y - 1][x + length]
                         - sum[y + length][x - 1] + sum[y - 1][x - 1];
            }
        }
    }
    
    return mx;
}
 
int main()
{
    int i, j;
 
    scanf("%d %d", &n, &m);
 
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1]
                            - sum[i - 1][j - 1] + map[i][j];
        }
    }
 
    printf("%d\n", search());
 
    return 0;
}
