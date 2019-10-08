#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m, safe=-3, virus=1e9;
int a[8][8];
bool c[8][8];
vector<pair<int, int>> v;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int dfs(int x, int y) {
    int res = 1;
    c[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (c[nx][ny] || a[nx][ny]) continue;
        res += dfs(nx, ny);
    }
    return res;
}

void solve(int wall, int x, int y) {
    if (wall == 3) {
        int cnt = 0;
        memset(c, 0, sizeof(c));
        for (auto k : v) {
            cnt += dfs(k.first, k.second);
        }
        if (virus > cnt) virus = cnt;
        return;
    }
    for (int i=x; i<n; i++) {
        int k = i == x ? y : 0;
        for (int j=k; j<m; j++) {
            if (a[i][j] == 0) {
                a[i][j] = 1;
                solve(wall+1, i, j+1);
                a[i][j] = 0;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 1) safe++;
            if (a[i][j] == 2) v.push_back({i, j});
        }
    }
    solve(0, 0, 0);
    printf("%d\n", safe-virus);
    return 0;
}


