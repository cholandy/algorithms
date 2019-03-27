#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 111111

using namespace std;
int N, M, G = 0;
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, 1, -1, 0 };
int map[100][100];
int ans = 0;
int visit[100][100];

void bfs(int iy, int ix){
    int limit = map[iy][ix];
    int lar = INF;
    bool f = false;

    queue<pair<int, int>> q;
    vector<pair<int, int>> pos;
    ++G;

    q.push({ iy, ix });
    visit[iy][ix] = G;
    pos.push_back({ iy, ix });

    while (!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        if (y == 0 || y == N - 1 || x == 0 || x == M - 1){
            f = true; break;
        }
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (map[ny][nx] <= limit && visit[ny][nx] < G){
                visit[ny][nx] = G;
                q.push({ ny, nx });
                pos.push_back({ ny, nx });
            }

            if (map[ny][nx] > limit)
                lar = min(lar, map[ny][nx]);
        }
    }

    if (!f)
    {
        for (auto i : pos){
            ans += lar - map[i.first][i.second];
            map[i.first][i.second] = lar;
        }
    }
}
int main(){
    scanf("%d%d", &N, &M);
    for (int n = 0; n < N; n++)
        for (int m = 0; m < M; m++)
            scanf("%d", &map[n][m]);
    for (int n = 0; n < N; n++){
        for (int m = 0; m < M; m++){
            if (n == 0 || n == N - 1 || m == 0 || m == M - 1) continue;
            bfs(n, m);
        }
    }
    printf("%d\n", ans);
    return 0;
}
