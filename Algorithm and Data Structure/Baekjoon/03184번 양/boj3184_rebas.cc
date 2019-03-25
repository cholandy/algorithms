#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int r, c, sheep, wolf;
char a[251][251];
bool check[251][251];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    check[i][j] = true;
    int o = 0, v = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        if (a[x][y] == 'o') o++;
        if (a[x][y] == 'v') v++;
        for (int k=0; k<4; k++) {
            int nx = x+dx[k], ny = y+dy[k];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (check[nx][ny] || a[nx][ny] == '#') continue;
            q.push(make_pair(nx, ny));
            check[nx][ny] = true;
        }
    }
    if (o > v) sheep += o;
    else wolf += v;
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i=0; i<r; i++) scanf("%s", a[i]);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (!check[i][j] && a[i][j] != '#') {
                bfs(i, j);
            }
        }
    }
    printf("%d %d\n", sheep, wolf);
    return 0;
}


