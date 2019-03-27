#include <iostream>
#define MX 510
using namespace std;
 
struct kkk{
    int r, br, n;
}q[MX * 2*MX];
 
int map[MX][2 * MX], mapnum[MX][2 * MX], check[MX * MX], graph[MX * MX][7], dab[MX*MX];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int N, st, ed, ir, point, pointpos, cnt, sw;
 
void bfs()
{
    st = ed = -1;
    q[++st].r = 1; q[st].br = -1; q[st].n = 1; check[1] = 1;
    while (st != ed)
    {
        ir = q[++ed].r;
        for (int i = 0; i < 6; i++)
        {
            if (check[graph[ir][i]]) continue;
            if (!graph[ir][i]) break;
            q[++st].r = graph[ir][i]; q[st].br = ed; q[st].n = q[ed].n + 1; check[graph[ir][i]] = 1;
            if (point < graph[ir][i])
            {
                point = graph[ir][i]; pointpos = st;
            }
            if (q[st].r == cnt) { sw = 1; break; }
        }
        if (sw) break;
    }
}
 
void way()
{
    int next = -1, pos = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 2 * N; j++)
        {
            if (!map[i][j]) continue;
            if (pos != mapnum[i][j]) next = -1;
            for (int k = 0; k < 4; k++)
            {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (nx < 1 || ny < 1 || nx > 2 * N || ny > N) continue;
                if (mapnum[ny][nx] == mapnum[i][j]) continue;
                if (map[ny][nx] != map[i][j]) continue;
                graph[mapnum[i][j]][++next] = mapnum[ny][nx];
            }
            pos = mapnum[i][j];
        }
    }
}
 
void find(int n)
{
    int k = -1;
    while (n >= 0)
    {
        dab[++k] = q[n].r;
        n = q[n].br;
    }
}
 
int main(void)
{
    cin >> N;
 
    for (int i = 1; i <= N; i++)
    {
        if (i % 2)
        {
            for (int j = 1; j <= 2 * N; j += 2)
            {
                cin >> map[i][j] >> map[i][j + 1];
                mapnum[i][j] = ++cnt; mapnum[i][j + 1] = cnt;
            }
        }
        else
        {
            for (int j = 2; j <= 2 * (N - 1); j += 2)
            {
                cin >> map[i][j] >> map[i][j + 1];
                mapnum[i][j] = ++cnt; mapnum[i][j + 1] = cnt;
            }
        }
    }
    way();
    bfs();
    if (sw)
    {
        int k = q[st].n;
        cout << k << endl;
        find(st);
        for (int i = k - 1; i >= 0; i--)
            cout << dab[i] << " ";
        cout << endl;
    }
    else
    {
        int k = q[pointpos].n;
        cout << k << endl;
        find(pointpos);
        for (int i = k - 1; i >= 0; i--)
            cout << dab[i] << " ";
        cout << endl;
    }
    return 0;
}
