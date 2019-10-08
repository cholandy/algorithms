#include <cstdio>
#include <cstring>
#define abs(x) (((x)>0)?(x):(-(x)))
using namespace std;

struct nation {
    int x, y;
};

int N, L, R, cnt, ans;
int a[50][50];
bool check[50][50], moving[50][50];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y) {
    check[x][y] = true;
    int population = a[x][y];
    for (int k=0; k<4; k++) {
        int nx = x+dx[k], ny = y+dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        int diff = abs(a[x][y]-a[nx][ny]);
        if (diff < L || diff > R || check[nx][ny]) continue;
        moving[nx][ny] = true;
        cnt++;
        population += dfs(nx, ny);
    }
    return population;
}

void migrate(int p) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (moving[i][j]) {
                a[i][j] = p;
                moving[i][j] = false;
            }
        }
    }
}

void solve() {
    int ans = 0;
    while (true) {
        bool moved = false;
        memset(check, false, sizeof(check));
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (!check[i][j]) {
                    cnt = 1;
                    int population = dfs(i, j)/cnt;
                    if (cnt > 1) {
                        a[i][j] = population;
                        migrate(population);
                        moved = true;
                    }
                }
            }
        }
        if (moved) ans++;
        else break;
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d %d %d", &N, &L, &R);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    solve();
    return 0;
}


