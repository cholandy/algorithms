#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct ele {
    int x, y, z;
    ele(int x, int y, int z) :x(x), y(y), z(z) {}
    ele() {}
};
int dx[] = { 1,-1,0,0,0 };
int dy[] = { 0,0,1,-1,0 };
int dz[] = { 0,0,0,0,1 };
int fx[] = { -1,-1,-1,0,0,0,1,1,1 };
int fy[] = { 1,-1,0,1,-1,0,1,-1,0 };
char a[55][55];
int n, disc[55][55][2];
int chk(int x, int y) {
    return 0 <= x&&x < n && 0 <= y&&y < n;
}
bool psb(ele e, int move) {
    int x = e.x, y = e.y, z = e.z;
    if (move == 4) {
        for (int i = 0; i < 9; i++) {
            if (!chk(x + fx[i], y + fy[i]))return false;
            if (a[x + fx[i]][y + fy[i]] == '1')return false;
        }
        return true;
    }
    else {
        int lx, ly, rx, ry;
        if (z == 1) {
            lx = x + 1 + dx[move], ly = y + dy[move], rx = x - 1 + dx[move], ry = y + dy[move];
            x += dx[move], y += dy[move];
            if (chk(lx, ly) && chk(x, y) && chk(rx, ry) && a[lx][ly] != '1'&&a[rx][ry] != '1'&&a[x][y] != '1')
                return true;
        }
        else {
            lx = x + dx[move], ly = y + 1 + dy[move], rx = x + dx[move], ry = y - 1 + dy[move];
            x += dx[move], y += dy[move];
            if (chk(lx, ly) && chk(x, y) && chk(rx, ry) && a[lx][ly] != '1'&&a[rx][ry] != '1'&&a[x][y] != '1')
                return true;
        }
    }
    return false;
}
ele s, e;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%s", &a[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'B') {
                if (chk(i - 1, j) && chk(i + 1, j) && a[i - 1][j] == 'B'&&a[i + 1][j] == 'B')
                    s = ele(i, j, 1);
                if (chk(i, j - 1) && chk(i, j + 1) && a[i][j - 1] == 'B'&&a[i][j + 1] == 'B')
                    s = ele(i, j, 0);
            }
            if (a[i][j] == 'E') {
                if (chk(i - 1, j) && chk(i + 1, j) && a[i - 1][j] == 'E'&&a[i + 1][j] == 'E')
                    e = ele(i, j, 1);
                if (chk(i, j - 1) && chk(i, j + 1) && a[i][j - 1] == 'E'&&a[i][j + 1] == 'E')
                    e = ele(i, j, 0);
            }
        }
    }
    queue<ele> qu;
    disc[s.x][s.y][s.z] = 1;
    qu.push(s);
    int res = 0;
    while (qu.size()) {
        int qs = qu.size();
        while (qs--) {
            ele here = qu.front();
            qu.pop();
            if (here.x == e.x&&here.y == e.y&&here.z == e.z) {
                printf("%d\n", res);
                return 0;
            }
            for (int i = 0; i < 5; i++) {
                if (!psb(here, i))continue;
                int nx = here.x + dx[i];
                int ny = here.y + dy[i];
                int nz = here.z^dz[i];
                if (disc[nx][ny][nz])continue;
                disc[nx][ny][nz] = 1;
                qu.push(ele(nx, ny, nz));
            }
        }
        res++;
    }
    puts("0");
    return 0;
}