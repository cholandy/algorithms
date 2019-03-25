#include <bits/stdc++.h>
using namespace std;
bool range[101][101];
bool visited[101][101];
int M, N, K;
void DFS(int y, int x, int &area) {
    visited[y][x] = true;
    area++;

    // -1 0 / +1 0 / 0 -1 / 0 +1
    vector<pair<int, int> > wsad;
    wsad.push_back({-1, 0});
    wsad.push_back({+1, 0});
    wsad.push_back({0, -1});
    wsad.push_back({0, +1});

    for (int i = 0; i < 4; i++) {
        int nextY = y + wsad[i].first;
        int nextX = x + wsad[i].second;
        bool yCheck = (nextY >= 0) && (nextY < M);
        bool xCheck = (nextX >= 0) && (nextX < N);
        if (yCheck && xCheck) {
            if (!range[nextY][nextX] && !visited[nextY][nextX])
                DFS(nextY, nextX, area);
        }
    }
}

int main() {
    vector<int> area;
    cin >> M >> N >> K;
    while (K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                range[i][j] = true;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            // 네모 영역이 아니면서 방문하지 않은 곳
            if (!range[i][j] && !visited[i][j]) {
                int ar = 0;
                DFS(i, j, ar);
                area.push_back(ar);
            }
        }
    }
    sort(area.begin(), area.end());
    cout << area.size() << '\n';
    for (auto i : area) {
        cout << i << " ";
    }
}