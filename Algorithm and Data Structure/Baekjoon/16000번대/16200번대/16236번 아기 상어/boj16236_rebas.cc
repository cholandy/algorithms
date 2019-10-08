#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct shark {
    int d, x, y;
    // Min Heap (priority : distance > x position > y position)
    bool operator < (const shark &t) const {
        if (d == t.d) {
            if (x == t.x) return y > t.y;
            else return x > t.x;
        } else return d > t.d;
    }
};

int n, body, eat, ans;
int a[20][20];
bool check[20][20];
priority_queue<shark> q;
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

void bfs() {
    while (!q.empty()) {
        int d = q.top().d, x = q.top().x, y = q.top().y;
        q.pop();
        // Shark can eat fish, if fish is smaller than shark.
        if (0 < a[x][y] && a[x][y] < body) {
            // Count eating fish.
            a[x][y] = 0;
            eat++;
            // Body size + 1
            if (eat == body) {
                body++;
                eat = 0;
            }
            ans += d;
            // Initializing distance, visited check, and queue.
            d = 0;
            memset(check, false, sizeof(check));
            while (!q.empty()) q.pop();
        }
        for (int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            // Cannot pass if fish is bigger than shark, or already visited.
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (check[nx][ny]) continue;
            if (0 < a[nx][ny] && a[nx][ny] > body) continue;
            // Update next moving.
            q.push({d+1, nx, ny});
            check[nx][ny] = true;
        }
    }
}

void solve() {
    body = 2;
    bfs();
    printf("%d\n", ans);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 9) {
                q.push({0, i, j});
                a[i][j] = 0;
            }
        }
    }
    solve();
    return 0;
}


