#include <stdio.h>
#include <queue>
using namespace std;
 
int n, m, k, x, y, v, ax, ay;
int map[1000][1000];
int d[1000][1000][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
 
struct Node {
    int x;
    int y;
    int v; //벽을 몇개 뚫었는지
    Node(int _x, int _y, int _v) {
        x = _x;
        y = _y;
        v = _v;
    }
};
 
void bfs(int a, int b) {
    d[a][b][0] = 1;
    queue<Node> q;
    q.push(Node(a, b, 0));
    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        v = q.front().v;
        q.pop();
        for (int i = 0; i < 4; i++) {
            ax = x + dx[i];
            ay = y + dy[i];
            if (ax >= 0 && ay >= 0 && ax < n&&ay < m) {
                if (map[ax][ay] == '0') {
                    if (v == 0) {
                        if (d[ax][ay][0] == 0 || d[ax][ay][0] > d[x][y][0] + 1) {
                            d[ax][ay][0] = d[x][y][0] + 1;
                            q.push(Node(ax, ay, 0));
                        }
                    }
                    
                    if (d[ax][ay][v] == 0 || d[ax][ay][v] > d[x][y][v] + 1) {
                        d[ax][ay][v] = d[x][y][v] + 1;
                        q.push(Node(ax, ay, v));
                    }
                }
                else {
                    if (v < k) {
                        if (d[ax][ay][v + 1] == 0 || d[ax][ay][v+1] > d[x][y][v]+1) {
                            d[ax][ay][v + 1] = d[x][y][v] + 1;
                            q.push(Node(ax, ay, v + 1));
                        }
                    }
                }
            }
        }
    }
}
 
void show() {
    for (int t = 0; t <= k; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", d[i][j][t]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
 
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = getchar();
        }
        getchar();
    }
 
    bfs(0, 0);
    int min = TMP_MAX;
    for (int i = 0; i <= k; i++) {
        if (d[n-1][m-1][i] != 0 && d[n - 1][m - 1][i] < min) {
            min = d[n - 1][m - 1][i];
        }
    }
    if (min == TMP_MAX) {
        printf("-1\n");
    }
    else {
        printf("%d\n", min);
    }
}
