#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<char, int> pci;
 
char arr[1003][1003];
bool visit[1003][1003];
 
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
 
int main()
{
    int w, h, n;
    int sx, sy;
    scanf("%d %d %d", &w, &h, &n);
 
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
        {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'S')
                sy = i, sx = j;
        }
 
 
    queue<pair<pci, pii> > q;
 
    q.push({ {'1', 0}, {sy, sx} });
 
    while (!q.empty())
    {
        int y = q.front().second.first;
        int x = q.front().second.second;
        char cnt = q.front().first.first;
        int num = q.front().first.second;
 
        q.pop();
        
        if (visit[y][x])
            continue;
 
        visit[y][x] = true;
 
        if (arr[y][x] == cnt)
        {
            while (!q.empty())
                q.pop();
 
            q.push({ {cnt + 1, num}, {y,x} });
            memset(visit, false, sizeof(visit));
            
            if(cnt == n + '0')
            {
                printf("%d", num);
                return 0;
            }
        
            continue;
        }
 
        
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            if (!(0 <= ny && ny < w) || !(0 <= nx && nx < h) || visit[ny][nx] || arr[ny][nx] == 'X')
                continue;
 
            q.push({ {cnt, num + 1},{ny,nx} });
        }
 
    }
 
    return 0;
}
 
