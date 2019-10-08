#include <iostream>
#include <cstdio>
#include <queue>
 
using namespace std;
 
typedef pair<int, int> pii;
 
int arr[1011][1011];
bool visit[1011][1011];
 
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &arr[i][j]);
 
    queue<pii> q;
 
    for(int i = 0 ; i < m ; i ++)
    {
        if (arr[0][i] == 1)
            continue;
 
        q.push({ 0,i });
 
        while (!q.empty())
        {
            int x = q.front().second;
            int y = q.front().first;
 
            q.pop();
 
            if (visit[y][x])
                continue;
 
            visit[y][x] = true;
 
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
 
                if(!(0 <= ny && ny < n) || !(0 <= nx && nx < m) || visit[ny][nx])
                    continue;
 
                if(arr[ny][nx] != 1)
                {
                    if (ny == n - 1)
                    {
                        printf("YES");
                        return 0;
                    }
 
                    q.push({ ny,nx });
                }
            }
        }
    }
 
    printf("NO");
 
    return 0;
}
