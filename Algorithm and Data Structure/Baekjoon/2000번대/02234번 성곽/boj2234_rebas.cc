#include <cstdio>

int n, m, A, B, C;
int a[50][50], check[50][50], area[2500];
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int dfs(int x, int y, int z) {
    check[x][y] = z;
    int res = 1;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if ((a[x][y] & (1<<i)) || check[nx][ny]) continue;
        res += dfs(nx, ny, z);
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (!check[i][j]) {
                A += 1;
                int k = dfs(i, j, A);
                if (B < k) B = k;
                area[A] = k;
            }
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<4; k++) {
                int ni = i+dx[k], nj = j+dy[k];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                int x = check[i][j], y = check[ni][nj];
                if (x != y) {
                    int sum = area[x]+area[y];
                    if (C < sum) C = sum;
                }
            }
        }
    }
    printf("%d\n%d\n%d\n", A, B, C);
    return 0;
}


