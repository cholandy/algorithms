#include <stdio.h>
 
int r, c, k;
bool chk[1001][1001];
 
int dx[5] = { 0, -1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int gd[4];
int cnt = 0;
 
void f(int x, int y, int i) {
    chk[x][y] = true;
    int nx = x + dx[gd[i]];
    int ny = y + dy[gd[i]];
    if (nx == -1 || nx == r || ny == -1 || ny == c || chk[nx][ny]) {
        if (cnt == 4) {
            printf("%d %d\n", x, y);
            return;
        }
        cnt++;
        f(x, y, (i + 1) % 4);
        return;
    }
    else {
        cnt = 0;
        f(nx, ny, i);
        return;
    }
}
 
int main(void) {
    scanf("%d %d", &r, &c);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        chk[a][b] = true;
    }
    int sx, sy;
    scanf("%d %d", &sx, &sy);
 
    for (int i = 0; i < 4; i++) {
        scanf("%d", &gd[i]);
    }
 
    f(sx, sy, 0);
}
