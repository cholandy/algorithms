#include <iostream>
#include <cstdio>
#include <queue>
 
using namespace std;
 
int arr[300][300];
bool visit[300][300];
 
int dy[8] = { 1,0,-1,0, -1, -1, 1, 1 };
int dx[8] = { 0,1,0,-1, -1, 1, -1, 1 };
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
 
    queue<pair<int, int> > q;
 
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (visit[i][j] || !arr[i][j])
                continue;
 
            cnt++;
 
            q.push({ i,j });
 
            while (!q.empty())
            {
                int y = q.front().first;
                int x = q.front().second;
 
                q.pop();
 
                if (visit[y][x])
                    continue;
 
                visit[y][x] = true;
 
                for (int i = 0; i < 8; i++)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
 
                    if (!(0 <= ny && ny < n) || !(0 <= nx && nx < m) || !arr[ny][nx] || visit[ny][nx])
                        continue;
 
                    q.push({ ny,nx });
                }
            }
        }
 
    cout << cnt;
    return 0;
}
