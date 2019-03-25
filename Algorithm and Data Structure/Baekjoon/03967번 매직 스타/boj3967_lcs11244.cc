#include <iostream>
#define MX 60
using namespace std;
 
struct KKK {
    int x, y;
}arr[15];
 
char map[6][10];
int check[MX / 2];
int flag, cnt;
 
void dfs(int d, int pos)
{
    if (d == cnt)
    {
        if (map[0][4] + map[1][3] + map[2][2] + map[3][1] - 4 * 'A' + 4 != 26) return;
        if (map[0][4] + map[1][5] + map[2][6] + map[3][7] - 4 * 'A' + 4 != 26) return;
        if (map[3][1] + map[3][3] + map[3][5] + map[3][7] - 4 * 'A' + 4 != 26) return;
        if (map[1][1] + map[1][3] + map[1][5] + map[1][7] - 4 * 'A' + 4 != 26) return;
        if (map[1][1] + map[2][2] + map[3][3] + map[4][4] - 4 * 'A' + 4 != 26) return;
        if (map[1][7] + map[2][6] + map[3][5] + map[4][4] - 4 * 'A' + 4 != 26) return;
        flag = 1;
        return;
    }
    for (int i = 0; i < 12; i++)
    {
        if (check[i]) continue;
        check[i] = 1;
        map[arr[pos].y][arr[pos].x] = i + 'A';
        dfs(d + 1, pos + 1);
        if (flag) return;
        map[arr[pos].y][arr[pos].x] = 'x';
        check[i] = 0;
    }
}
 
int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        cin >> map[i];
        for (int j = 0; j < 9; j++)
        {
            if ('A' <= map[i][j] && map[i][j] <= 'L') check[map[i][j] - 'A'] = 1;
            if (map[i][j] == 'x') { arr[cnt].x = j; arr[cnt].y = i; cnt++; }
        }
    }
 
    dfs(0, 0);
    
    for (int i = 0; i < 5; i++)
        cout << map[i] << endl;
 
    return 0;
}
