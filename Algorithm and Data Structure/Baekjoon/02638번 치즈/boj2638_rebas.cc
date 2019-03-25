#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct cheese {
    int x, y;
};

int n, m, ans;
int a[100][100];
bool check[100][100];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void bfs() {
    memset(check, false, sizeof(check));
    queue<cheese> q;
    q.push({0, 0});
    check[0][0] = true;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y; q.pop();
        for (int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (check[nx][ny]) continue;
            if (a[nx][ny] >= 1) {
                a[nx][ny] += 1;
                continue;
            }
            q.push({nx, ny});
            check[nx][ny] = true;
        }
    }
}

bool melt() {
    bool melted = false;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] >= 3) {
                a[i][j] = 0;
                melted = true;
            } else if (a[i][j] == 2) a[i][j] = 1;
        }
    }
    return melted;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    while (true) {
        bfs();
        if (melt()) ans++;
        else break;
    }
    printf("%d\n", ans);
    return 0;
}


