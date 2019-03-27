#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <memory.h>
 
using namespace std;
 
typedef pair<int, int> pii;
 
int arr[102][102];
bool visit[102][102];
 
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int main()
{
    int n;
    int min_val = 500;
    int max_val = 0;
 
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            min_val = min(min_val, arr[i][j]);
            max_val = max(max_val, arr[i][j]);
        }
 
    int start = 0, end = 200;
    int get = 500;
 
    while (start <= end)
    {
        int mid = (start + end) / 2;
 
        bool in = false;
        bool out = false;
        for (int bot = min_val; bot + mid <= max_val; bot++)
        {
            in = true;
 
            if (out)
                break;
 
            memset(visit, 0, sizeof(visit));
 
            if (arr[0][0] < bot || arr[0][0] > bot + mid)
                continue;
 
            queue<pii> q;
 
            q.push({ 0,0 });
            while (!q.empty())
            {
                int y = q.front().first;
                int x = q.front().second;
 
                q.pop();
 
                if (visit[y][x])
                    continue;
 
                visit[y][x] = true;
 
                for (int i = 0; i < 4; i++)
                {
                    int ny = dy[i] + y;
                    int nx = dx[i] + x;
 
                    if (!((0 <= ny && ny < n) && (0 <= nx && nx < n)))
                        continue;
 
                    if (visit[ny][nx])
                        continue;
 
                    if (arr[ny][nx] < bot || arr[ny][nx] > bot + mid)
                        continue;
 
                    q.push({ ny,nx });
 
                    if (ny == n - 1 && nx == n - 1)
                        out = true;
                }
            }
        }
 
        if (!in || out)
        {
            get = min(mid, get);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    printf("%d", get);
 
    return 0;
}


출처: https://www.crocus.co.kr/999?category=159837 [Crocus]