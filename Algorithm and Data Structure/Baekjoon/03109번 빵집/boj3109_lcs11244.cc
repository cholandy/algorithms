#include <iostream>
#include <memory.h>
#define MX 10005
using namespace std;
 
char map[MX][503];
int check[MX][503];
int dx[] = { 1, 1, 1 };
int dy[] = { -1, 0, 1 };
int R, C, dab;
 
int dfs(int x, int y)
{
    map[y][x] = 'x';
    if (x == C - 1) return 1;
    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= C || ny >= R || map[ny][nx] == 'x') continue;
        if (dfs(nx, ny)) return 1;
    }
    return 0;
}
 
int main(void)
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> map[i];
    for (int i = 0; i < R; i++)
        dab += dfs(0, i);
    cout << dab << '\n';
    return 0;
}
