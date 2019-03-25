#include <cstdio>

int n, m, ans = 1;
int x, y, d;
int a[50][50];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
    while (true) {
        bool clean = false;
        for (int k=0; k<4; k++) {
            int nd = (d+3)%4;
            int nx = x+dx[nd], ny = y+dy[nd];
            d = nd;
            if (!a[nx][ny]) {
                a[nx][ny] = 2;
                ans += 1;
                x = nx, y = ny;
                clean = true;
                break;
            }
        }
        if (!clean) {
            if (a[x-dx[d]][y-dy[d]] == 1) return;
            else x -= dx[d], y -= dy[d];
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &y, &d);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    a[x][y] = 2;
    solve();
    printf("%d\n", ans);
    return 0;
}


