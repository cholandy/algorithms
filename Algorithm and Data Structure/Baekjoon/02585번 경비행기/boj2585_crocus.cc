#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <memory.h>
 
using namespace std;
 
typedef pair<int, int> pii;
 
pii adj[1005];
bool visit[1005];
 
double getLength(int s, int e, int x, int y)
{
    return sqrt((s-x)*(s-x) + (e-y)*(e-y)) / 10;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
 
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[i].first = x;
        adj[i].second = y;
    }
 
    int start = 0;
    int end = 1500;
    int ans = 987654312;
    
    while (start <= end)
    {
        int mid = (start + end) / 2;
 
        bool once = false;
 
        bool chk = true;
 
        memset(visit, false, sizeof(visit));
        queue<pair<pii, int> > q;
 
        q.push({{ 0,0 }, k});
            
        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int cnt = q.front().second;
 
            q.pop();
        
            if (cnt < 0)
                continue;
 
            if (getLength(10000, 10000, x, y) <= (double)mid)
            {
                once = true;
                break;
            }
            for (int i = 0; i < n; i++)
            {
                int nx = adj[i].first;
                int ny = adj[i].second;
 
                if (visit[i])
                    continue;
 
                if (getLength(nx, ny, x, y) <= (double)mid)
                {
                    q.push({ { nx, ny}, cnt - 1 });
                    visit[i] = true;
                }
            }
        }
 
        if (once)
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
 
    cout << ans << endl;
    return 0;
}
