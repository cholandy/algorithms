#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int life[22];
int happy[22];
int n;
int ans;
void dfs(int i, int nowLife, int nowHappy)
{
    for (i = i + 1; i < n; i++)
    {
        if (nowLife - life[i] <= 0)
            continue;
 
        ans = max(nowHappy + happy[i], ans);
        dfs(i, nowLife - life[i], nowHappy + happy[i]);
    }
}
int main()
{
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
        scanf("%d", &life[i]);
 
    for (int i = 0; i < n; i++)
        scanf("%d", &happy[i]);
 
    for (int i = 0; i < n; i++)
    {
        if (100 - life[i] <= 0)
            continue;
 
        ans = max(0 + happy[i], ans);
 
        dfs(i, 100 - life[i], 0 + happy[i]);
    }
 
    cout << ans;
    
    return 0;
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
