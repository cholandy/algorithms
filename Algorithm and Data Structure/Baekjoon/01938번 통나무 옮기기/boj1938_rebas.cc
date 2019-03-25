#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct tree {
    int x, y, z;
};

int n, m;
char a[50][50];
int dist[50][50][2];
queue<tree> q;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

bool out(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

bool check(int x, int y) {
    if (out(x, y) || a[x][y] == '1') return false;
    return true;
}

void one(int x, int y, int z, int dx, int dy) {
    if (!out(x+dx, y+dy) && a[x+dx][y+dy] != '1' && dist[x][y][z] == -1) {
        q.push({x, y, z});
        dist[x][y][z] = dist[x-dx][y-dy][z]+1;
    }
}

void three(int x, int y, int z, int nx, int ny, int dx, int dy) {
    if (!out(nx, ny) && dist[nx][ny][z] == -1) {
        if (a[nx][ny] != '1' && a[nx-dx][ny-dy] != '1' && a[nx+dx][ny+dy] != '1') {
            q.push({nx, ny, z});
            dist[nx][ny][z] = dist[x][y][z]+1;
        }
    }
}

void rotate(int x, int y, int z) {
    for (int i=0; i<8; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if (!check(nx, ny)) return;
    }
    if (dist[x][y][!z] == -1) {
        q.push({x, y, !z});
        dist[x][y][!z] = dist[x][y][z]+1;
    }
}

void bfs() {
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, z = q.front().z; q.pop();
        int mx = 0, my = 0;
        if (z) mx = 1;
        else my = 1;
        if (a[x][y] == 'E' && a[x-mx][y-my] == 'E' && a[x+mx][y+my] == 'E') {
            printf("%d\n", dist[x][y][z]);
            return;
        }
        if (z) {
            one(x-1, y, z, -1, 0);
            one(x+1, y, z, 1, 0);
            three(x, y, z, x, y+1, 1, 0);
            three(x, y, z, x, y-1, 1, 0);
            rotate(x, y, z);
        }
        else {
            one(x, y-1, z, 0, -1);
            one(x, y+1, z, 0, 1);
            three(x, y, z, x+1, y, 0, 1);
            three(x, y, z, x-1, y, 0, 1);
            rotate(x, y, z);
        }
    }
    printf("0\n");
}

int main() {
    scanf("%d", &n);
    memset(dist, -1, sizeof(dist));
    vector<tree> v;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf(" %1c", &a[i][j]);
            if (a[i][j] == 'B') v.push_back({i, j});
        }
    }
    int x = v[1].x, y = v[1].y, z = v[0].x != v[1].x;
    q.push({x, y, z});
    dist[x][y][z] = 0;
    bfs();
    return 0;
}


