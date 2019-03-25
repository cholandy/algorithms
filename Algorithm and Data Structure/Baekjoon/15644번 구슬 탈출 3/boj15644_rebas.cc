#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct bead {
    int rx, ry, bx, by, d;
};

int n, m;
char a[10][10];
bool check[10][10][10][10];
bead path[10][10][10][10];
queue<bead> q;
const char direct[] = {'U', 'R', 'D', 'L'};
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void move(int &x, int &y, int &c, int dx, int dy) {
    while (a[x+dx][y+dy] != '#' && a[x][y] != 'O') {
        x += dx;
        y += dy;
        c += 1;
    }
}

void bfs() {
    while (!q.empty()) {
        int rx = q.front().rx, ry = q.front().ry;
        int bx = q.front().bx, by = q.front().by;
        int d = q.front().d; q.pop();
        if (d >= 10) break;
        for (int i=0; i<4; i++) {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int rc = 0, bc = 0, nd = d+1;
            move(nrx, nry, rc, dx[i], dy[i]);
            move(nbx, nby, bc, dx[i], dy[i]);
            if (a[nbx][nby] == 'O') continue;
            if (a[nrx][nry] == 'O') {
                vector<char> p;
                p.push_back(direct[i]); // Current direct
                bead &b = path[rx][ry][bx][by];
                while (b.rx != 0) {
                    int mrx = b.rx, mry = b.ry, mbx = b.bx, mby = b.by;
                    p.push_back(direct[b.d]); // Go backward previous position.
                    b = path[mrx][mry][mbx][mby];
                }
                printf("%d\n", nd);
                int len = p.size();
                for (int k=0; k<len; k++) { // Print in reverse order.
                    printf("%c", p[len-k-1]);
                }
                printf("\n");
                return;
            }
            if (nrx == nbx && nry == nby) {
                if (rc > bc) nrx -= dx[i], nry -= dy[i];
                else nbx -= dx[i], nby -= dy[i];
            }
            if (check[nrx][nry][nbx][nby]) continue;
            check[nrx][nry][nbx][nby] = true;
            q.push({nrx, nry, nbx, nby, nd});
            path[nrx][nry][nbx][nby] = {rx, ry, bx, by, i};
        }
    }
    printf("-1\n");
}

int main() {
    scanf("%d %d", &n, &m);
    int rx = 0, ry = 0, bx = 0, by = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1s", &a[i][j]);
            if (a[i][j] == 'R') rx = i, ry = j;
            else if (a[i][j] == 'B') bx = i, by = j;
        }
    }
    q.push({rx, ry, bx, by, 0});
    check[rx][ry][bx][by] = true;
    bfs();
    return 0;
}
