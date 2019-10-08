#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

int n, m, s, a[11][11], chk[11][11];
vector<pair<int, int> > virus;

int dfs(int x, int y) {
    int ret = 1;
    chk[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if (chk[nx][ny]) continue;
        ret += dfs(nx, ny);
    }
    return ret;
}

int go(int x, int y, int cnt) {
    int ret = 1e9;
    if (cnt == 3) {
        for (int i = 0; i <= n+1; i++) {
            for (int j = 0; j <= m+1; j++) {
                chk[i][j] = a[i][j];
            }
        }
        int res = 0;
        for (auto it : virus) {
            res += dfs(it.first, it.second);
        }
        return res - virus.size();
    }
    for (int i = x; i <= n; i++) {
        int tmp = 1;
        if (i == x) tmp = y;
        for (int j = tmp; j <= m; j++) {
            if (a[i][j]) continue;
            a[i][j] = 1;
            ret = min(ret, go(i, j+1, cnt+1));
            a[i][j] = 0;
        }
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0) {
                s++;
            }
            if (a[i][j] == 2) {
                virus.push_back({ i,j });
            }
        }
    }

    printf("%d\n", s-3-go(1, 1, 0));

    return 0;
}