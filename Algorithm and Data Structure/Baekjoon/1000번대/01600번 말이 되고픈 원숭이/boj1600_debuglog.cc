#include <cstdio>
#include <queue>
#include <algorithm>
​
using namespace std;
​
int k;
int w, h;
int map[201][201];
bool visited[201][201][31] = { false };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int kdx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int kdy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
​
struct pos {
    int x;
    int y;
    int k;
    int cnt;
    pos(int a, int b, int c, int d) : x(a), y(b), k(c), cnt(d) {}
};
​
int bfs(int k) {
    queue<pos> q;
    q.push(pos(0, 0, k, 0));
​
    while (!q.empty()) {
        pos cur = q.front();
        q.pop();
​
        if (cur.x < 0 || cur.y <0 || cur.x >= w || cur.y >= h) continue;
        if (map[cur.y][cur.x]) continue;
​
        if (cur.x == w - 1 && cur.y == h - 1) {
            return cur.cnt;
        }
​
        if (visited[cur.y][cur.x][cur.k]) continue;
        visited[cur.y][cur.x][cur.k] = true;
        
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            q.push(pos(nx, ny, cur.k, cur.cnt + 1));
        }
​
        if (cur.k == 0) continue;
        for (int i = 0; i < 8; i++) {
            int nx = cur.x + kdx[i];
            int ny = cur.y + kdy[i];
            q.push(pos(nx, ny, cur.k - 1, cur.cnt + 1));
        }
    }
​
    return -1;
}
​
int main(void) {
    scanf("%d %d %d", &k, &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &map[i][j]);
        }
    }
​
    printf("%d\n", bfs(k));
​
    return 0;
}