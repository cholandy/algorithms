#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
 
using namespace std;
 
typedef pair<int, int> pii;
 
int abs(int a, int b) {
    return a > b ? a - b : b - a;
}
 
int arr[52][52];
int tmp[52][52];
 
int alliance[52][52];
bool visit[52][52];
int color;
 
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
 
int n, l, r, ans;
vector<pii> bfs(int i, int j) {
    memset(visit, 0, sizeof(visit));
 
    queue<pii> q;
    vector<pii> vc;
    q.push({ i,j });
 
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
 
        q.pop();
 
        if (visit[y][x])
            continue;
 
        alliance[y][x] = color;
        vc.push_back({ y,x });
 
        visit[y][x] = true;
 
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            
            // 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 
            // 두 나라가 공유하는 국경선을 오늘 하루동안 연다.
            // 즉, 큐에 push하여 같은 색을 칠하도록 한다.
            if (0 <= ny && ny < n && 0 <= nx && nx < n && alliance[ny][nx] == -1) {
                int val = abs(arr[ny][nx] - arr[y][x]);
                if (l <= val && val <= r)
                    q.push({ ny,nx });
            }
        }
    }
 
    return vc;
}
int main() {
    scanf("%d %d %d", &n, &l, &r);
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
 
    bool chk = true;
    while (chk)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                tmp[i][j] = arr[i][j];
 
        // 연합을 해체하고, 모든 국경선을 닫는다.
        chk = false;
        memset(alliance, -1, sizeof(alliance));
        color = 1;
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (alliance[i][j] != -1)
                    continue;
 
                color++;
                vector<pii> vc = bfs(i, j);
 
                if (vc.size() == 1)
                    continue;
 
                // 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 
                // 인구 이동을 시작한다.
                // 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 
                // 그 나라를 오늘 하루 동안은 연합이라고 한다.
                chk = true;
                int ret = 0;
                for (int k = 0; k < vc.size(); k++)
                    ret += tmp[vc[k].first][vc[k].second];
 
                // 연합을 이루고 있는 각 칸의 인구수는 
                // (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 
                // 편의상 소수점은 버린다.
                ret /= vc.size();
                for (int k = 0; k < vc.size(); k++)
                    tmp[vc[k].first][vc[k].second] = ret;
            }
        }
 
        if (!chk)
            break;
        ans++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = tmp[i][j];
    }
 
    return !printf("%d",ans);
}