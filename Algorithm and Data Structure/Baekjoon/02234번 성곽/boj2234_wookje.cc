#include <cstdio>

const int dx[] = { 0,-1,0,1 };
const int dy[] = { -1,0,1,0 };

int n, m, a[55][55], c[55][55], cnt[55*55];

int dfs(int x, int y, int num) {
    int ret = 1;
    c[x][y] = num;
    for (int i = 0; i < 4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if ((a[x][y]&(1<<i)) || c[nx][ny]) continue;
        ret += dfs(nx, ny, num);
    }
    return ret;
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int num = 1, mx = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!c[i][j]) {
                cnt[num] = dfs(i, j, num);
                if (mx < cnt[num]) mx = cnt[num];
                num++;
            }
        }
    }

    int add = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            for (int d = 0; d < 4; d++) {
                int nx=x+dx[d], ny=y+dy[d], sum = 0;
                if (c[nx][ny] && c[x][y] != c[nx][ny])
                    sum = cnt[c[x][y]] + cnt[c[nx][ny]];
                if (add < sum) add = sum;
            }
        }
    }

    printf("%d\n%d\n%d", num-1, mx, add);

    return 0;
}