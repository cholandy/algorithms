#include <iostream>
#include <cstdio>
#include <string>
 
using namespace std;
 
char str[32][32];
 
int n;
 
bool limit(int y, int x)
{
    if (!(0 <= y && y < n) || !(0 <= x && x < n))
        return false;
 
    return true;
}
bool goGaro(int y, int x, int cnt, char ch)
{
    if (!limit(y, x) || str[y][x] != ch)
        return false;
 
    if (cnt == 3)
        return true;
 
    if (ch == str[y][x])
        return goGaro(y, x - 1, cnt + 1, ch);
 
}
bool goSero(int y, int x, int cnt, char ch)
{    
        if (!limit(y, x) || str[y][x] != ch)
        return false;
 
    if (cnt == 3)
        return true;
 
    if (ch == str[y][x])
        return goSero(y - 1, x, cnt + 1, ch);
}
bool goDia1(int y, int x, int cnt, char ch)
{
    if (!limit(y, x) || str[y][x] != ch)
        return false;
 
    if (cnt == 3)
        return true;
 
    if (ch == str[y][x])
        return goDia1(y - 1, x - 1, cnt + 1, ch);
}
bool goDia2(int y, int x, int cnt, char ch)
{
    if (!limit(y, x) || str[y][x] != ch)
        return false;
 
    if (cnt == 3)
        return true;
 
    if (ch == str[y][x])
        return goDia2(y - 1, x + 1, cnt + 1, ch);
}
int main()
{
    scanf("%d", &n);
 
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %c", &str[i][j]);
 
            if (str[i][j] == '.')
                continue;
 
            // 가로
            if (goGaro(i, j, 1, str[i][j]))
            {
                printf("%c", str[i][j]);
                return 0;
            }
 
            // 세로    
            if (goSero(i, j, 1, str[i][j]))
            {
                printf("%c", str[i][j]);
                return 0;
            }
 
            // ↘ 대각선
            if (goDia1(i, j, 1, str[i][j]))
            {
                printf("%c", str[i][j]);
                return 0;
            }
 
            // ↙ 대각선
            if (goDia2(i, j, 1, str[i][j]))
            {
                printf("%c", str[i][j]);
                return 0;
            }
        }
    }
 
    printf("ongoing");
    return 0;
}