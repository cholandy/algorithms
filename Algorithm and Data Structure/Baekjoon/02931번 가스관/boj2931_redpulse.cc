#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <set>
#include <list>
#include <utility>
#include <functional>
#define MAX 205
#define INF 987654321
#define MOD 1000000
typedef long long ll;
#pragma warning(disable:4996)
using namespace std;
 
int n, m, cy, cx, dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 }, u[4] = { 2,3,0,1 };
char c, map[30][30], str[7] = { 124,'-','+','1','2','3','4' };
bool tf[7][4] = { { 1,0,1,0 },{ 0,1,0,1 },{ 1,1,1,1 },{ 0,1,1,0 },{ 1,1,0,0 },{ 1,0,0,1 },{ 0,0,1,1 } };
bool visit[30][30], mem[4][30][30];
pair<int, int> p[2];
queue<pair<int, int>> q;
 
void bfs()
{
    while (!q.empty())
    {
        pair<int, int> tmp = q.front();
        q.pop();
        for (int i = 0; i<4; i++)
        {
            int ty = tmp.first + dy[i], tx = tmp.second + dx[i];
            if (visit[ty][tx] == false)
            {
                if (mem[i][tmp.first][tmp.second] && mem[u[i]][ty][tx])
                {
                    visit[ty][tx] = true;
                    q.push(make_pair(ty, tx));
                }
                else if (mem[i][tmp.first][tmp.second] || mem[u[i]][ty][tx])
                {
                    printf("%d %d ", ty, tx);
                    bool ans[4];
                    for (int k = 0; k<4; k++)
                    {
                        int ry = ty + dy[k], rx = tx + dx[k];
                        if (mem[u[k]][ry][rx])
                            ans[k] = true;
                        else
                            ans[k] = false;
                    }
                    for (int p = 0; p<7; p++)
                        for (int q = 0; q<4; q++)
                        {
                            if (ans[q] != tf[p][q])
                                break;
                            if (q == 3)
                            {
                                printf("%c", str[p]);
                                return;
                            }
                        }
                }
            }
        }
    }
}
 
int main()
{
    fill_n(&mem[0][0][0], 4 * 30 * 30, 0);
    fill_n(&map[0][0], 30 * 30, '.');
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        getchar();
        for (int k = 1; k <= m; k++)
        {
            scanf("%c", &c);
            map[i][k] = c;
            if (c == 'M')
                p[0].first = i, p[0].second = k;
            else if (c == 'Z')
                p[1].first = i, p[1].second = k;
            for (int p = 0; p<7; p++)
                if (c == str[p])
                    for (int q = 0; q<4; q++)
                        mem[q][i][k] = tf[p][q];
        }
    }
    for (int i = 0; i<2; i++)
    {
        for (int k = 0; k<4; k++)
        {
            int ty = p[i].first + dy[k], tx = p[i].second + dx[k];
            if (mem[u[k]][ty][tx])
                mem[k][p[i].first][p[i].second] = true;
        }
    }
    visit[p[0].first][p[0].second] = true;
    q.push(make_pair(p[0].first, p[0].second));
    bfs();
    return 0;
}