#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
int vis[101][101];
vector<pair<int, int>> land[10001];
bool OOB(int a, int b) {
    return a < 0 or a >= n or b < 0 or b >= n;
}

void island() {
    int island_number = 1;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (vis[i][j] or board[i][j] == 0) continue;
            queue<pair<int, int>> Q;
            Q.push({i,j});
            vis[i][j] = true;
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                board[cur.X][cur.Y] = island_number;
                land[island_number].push_back({cur.X, cur.Y});
                for (int dir=0; dir<4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (OOB(nx, ny) or vis[nx][ny] or board[nx][ny]==0) continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
            island_number++;
        }
    }
}

int min_bridge(int idx) {
    queue<tuple<int, int, int>> Q;
    for (auto e : land[idx]) {
        Q.push({e.X, e.Y, 0});
        vis[e.X][e.Y] = idx;
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int cx, cy, t;
        tie(cx, cy, t) = cur;
        for (int dir=0; dir<4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (OOB(nx, ny) or vis[nx][ny] == idx) continue;
            if (board[nx][ny] == idx) continue;
            if (board[nx][ny] != 0) return t;
            vis[nx][ny] = idx;
            Q.push({nx, ny, t+1});
        }
    }
    return 99999;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> board[i][j];
        }
    }
    island();
    int ans = 0x7f7f77ff;
    for (int i=1; i<10000; ++i) {
        if (land[i].empty()) break;
        ans = min(ans, min_bridge(i));
    }
    cout << ans;
}