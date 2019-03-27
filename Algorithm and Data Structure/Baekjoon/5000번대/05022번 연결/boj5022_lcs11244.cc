#include <iostream>
#include <memory.h>
#define MX 110
using namespace std;
 
struct CONNECT {
    int x, y, bf;
}q[MX*MX];
 
int map[MX][MX], check[4][MX][MX], A[MX][MX], B[MX][MX];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int N, M, st, ed, ix, iy, nx, ny, A1x, A1y, A2x, A2y, B1x, B1y, B2x, B2y, tmp, dab = 2100000000;
 
void bfs(int d, int stx, int sty, int edx, int edy)
{
    st = ed = -1;
    q[++st].x = stx; q[st].y = sty; q[st].bf = -1; check[d][sty][stx] = 1;
    while (st != ed)
    {
        ix = q[++ed].x; iy = q[ed].y;
        if (ix == edx && iy == edy) return;
        for (int i = 0; i < 4; i++)
        {
            nx = ix + dx[i]; ny = iy + dy[i];
            if (nx < 0 || ny < 0 || nx > M || ny > N || check[d][ny][nx]) continue;
            q[++st].x = nx; q[st].y = ny; q[st].bf = ed; check[d][ny][nx] = 1;
        }
    }
}
 
bool find(int stx, int sty, int edx, int edy, int arr[MX][MX])
{
    if (arr[sty][stx]) return false;
    st = ed = -1;
    q[++st].x = stx; q[st].y = sty; arr[sty][stx] = 1;
    while (st != ed)
    {
        ix = q[++ed].x; iy = q[ed].y;
        if (ix == edx && iy == edy) { tmp += arr[iy][ix]; return true; }
        for (int i = 0; i < 4; i++)
        {
            nx = ix + dx[i]; ny = iy + dy[i];
            if (nx < 0 || ny < 0 || nx > M || ny > N) continue;
            if (arr[ny][nx]) continue;
            q[++st].x = nx; q[st].y = ny; arr[ny][nx] = arr[iy][ix] + 1;
        }
    }
    return false;
}
 
void connect(int arr[MX][MX])
{
    int k = ed;
    while (k > -1)
    {
        arr[q[k].y][q[k].x] = -1;
        tmp++;
        k = q[k].bf;
    }
}
 
int main(void)
{
    cin >> M >> N;
    cin >> A1x >> A1y >> A2x >> A2y;
    cin >> B1x >> B1y >> B2x >> B2y;
    check[0][B1y][B1x] = check[0][B2y][B2x] = check[1][A1y][A1x] = check[1][A2y][A2x] = -1;
    bfs(0, A1x, A1y, A2x, A2y);
    connect(A);
    if (find(B1x, B1y, B2x, B2y, A) && dab > tmp) dab = tmp;
    tmp = 0;
    bfs(1, B1x, B1y, B2x, B2y);
    connect(B);
    if (find(A1x, A1y, A2x, A2y, B) && dab > tmp) dab = tmp;
    if (dab == 2100000000) cout << "IMPOSSIBLE" << endl;
    else cout << dab - 2 << endl;
    return 0;
}
