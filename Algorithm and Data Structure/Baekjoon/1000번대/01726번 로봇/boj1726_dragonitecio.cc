#include <iostream>
#include <queue>
using namespace std;
#define SIZE 101 // 101;
#define qSIZE 130 // 130;
int map[SIZE][SIZE];
int visit[SIZE][SIZE][5];
 
int x, y, nx, ny;
struct point {
    int x, y, dir, cnt;
}que[qSIZE * qSIZE];
 
int rear, front;
int ans;
int M, N;
int dx[] = { 0,0,0,1,-1 };
int dy[] = { 0,1,-1,0,0 };
int startX, startY, endX, endY, startDir, endDir;
int dir, cnt;
 
void problemIn() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
 
    cin >> startX >> startY >> startDir;
    cin >> endX >> endY >> endDir;
    startX -= 1;
    startY -= 1;
    endX -= 1;
    endY -= 1;
}
 
void bfs() {
 
    while (rear != front) {
        front++;
        x = que[front].x;
        y = que[front].y;
        cnt = que[front].cnt;
        dir = que[front].dir;
 
        if (x == endX && y == endY && dir == endDir) {
            ans = cnt;
            return;
        }
 
        // 방향은 정해져 있음
        for (int i = 1; i <= 3; i++) {
            nx = x + dx[dir] * i;
            ny = y + dy[dir] * i;
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) break;
            if (map[nx][ny] == 1) break;
            if (visit[nx][ny][dir] == 0) {
                visit[nx][ny][dir] = 1;
                rear++;
                que[rear].x = nx;
                que[rear].y = ny;
                que[rear].dir = dir;
                que[rear].cnt = cnt + 1;
            }
        }
 
        // 현재 들은 것의 다른 방향에 대해서도 que 에 넣겠음
        for (int i = 1; i < 5; i++) {
            if (visit[x][y][i] == 0) {
                visit[x][y][i] = 1;
                rear++;
                que[rear].x = x;
                que[rear].y = y;
                que[rear].dir = i;
                if (dir == 1) {
                    if (i == 2) que[rear].cnt = cnt + 2; 
                    else que[rear].cnt = cnt + 1;
                }
                else if (dir == 2) {
                    if (i == 1) que[rear].cnt = cnt + 2;
                    else que[rear].cnt = cnt + 1;
                }
                else if (dir == 3) {
                    if (i == 4) que[rear].cnt = cnt + 2; 
                    else que[rear].cnt = cnt + 1;
 
                }
                else if (dir == 4) {
                    if (i == 3) que[rear].cnt = cnt + 2;
                    else que[rear].cnt = cnt + 1;
                }
            }
        }
    }
}
 
 
 
void solve() {
 
    front = rear = -1;
    rear++;
    que[rear].x = startX;
    que[rear].y = startY;
    que[rear].dir = startDir;
    que[rear].cnt = 0;
    visit[startX][startY][startDir] = 1;
    bfs();
 
}
 
int main() {
    problemIn();
    solve();
    cout << ans << endl;
    return 0;
}
