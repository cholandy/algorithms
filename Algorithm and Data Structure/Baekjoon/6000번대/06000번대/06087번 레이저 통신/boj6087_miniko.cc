#include<cstdio>
#include<queue>
using namespace std;
struct p{
    int x, y, d;
};
int visit[4][101][101], sx, sy, ex, ey, W, H, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0,1,0,-1 };
char map[101][101];
queue<p> q;
void bfs() {
    while (!q.empty()) {
        p t = q.front(); q.pop();
        for (int i = 0, tx,ty; i < 4; i++) {
            tx = t.x + dx[i], ty = t.y + dy[i];
            if (tx >= 0 && tx < W && ty >= 0 && ty < H && map[ty][tx] != '*') {
                int& t1 = visit[i][ty][tx], t2 = visit[t.d][t.y][t.x];
                if (t1 && t1 <= t2) continue;
                t1 = t2 + 1;
                if (t.d == i) t1--;
                q.push({ tx, ty ,i });
            }
        }
    }
}
int main() {
    scanf("%d%d", &W, &H);
    for (int i = 0; i < H; i++) 
        for (int j = 0; j < W; j++) {
            scanf(" %c", &map[i][j]);
            if (map[i][j] == 'C') {
                if (!sx) sx = j, sy = i;
                else ex = j, ey = i;
            }
        }
    for (int k = 0, tx, ty; k < 4; k++) {
        visit[k][sy][sx] = 1;
        q.push({ sx,sy,k });
    }
    bfs();
    int mi = 1e8;
    for (int i = 0, t; i < 4; i++) {
        t = visit[i][ey][ex];
        if (!t) continue;
        if (mi > t) mi = t;
    }
    printf("%d\n", mi-1);
    return 0;
}
