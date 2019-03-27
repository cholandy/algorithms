/*
2018.04.04.1720
13901 로봇
지정한 방향이 계속해서 도는 구나,
이동 시뮬레이션 문제입니다.
*/
 
 
#include <iostream>
using namespace std;
#define SIZE 1005 // 1005
 
int R, C;
int k;
int command[4];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int x, y, nx, ny, dir;
int startX, startY;
int ox, oy;
int map[SIZE][SIZE];
int visit[SIZE][SIZE];
int turn_cnt;
int a;
 
 
void problemIn() {
    cin >> R >> C;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> ox >> oy;
        map[ox][oy] = 1; // 벽은 1 
    }
    cin >> startX >> startY;
    for (int i = 0; i < 4; i++) {
        cin >> a;
        command[i] = a-1;
    }
}
 
/*
방향이 4번 바뀌었는데도 그자리이면, break 를 하면 됩니다.
*/
void solve() {
 
    x = startX;
    y = startY;
    visit[x][y] = 1;
    dir = 0;
 
    while (1) {
 
 
        nx = x + dx[command[dir]];
        ny = y + dy[command[dir]];
        if (nx < 0 || ny < 0 || nx >= R || ny >= C || map[nx][ny] != 0 || visit[nx][ny] != 0 ) {
            turn_cnt++;
            if (turn_cnt >= 4) {
                return;
            }
            dir = (dir + 1) % 4;
        }
        else {
            x = nx;
            y = ny;
            visit[nx][ny] = 1;
            turn_cnt = 0;
            //dir = (dir + 1) % 4;
        }
    }
}
 
int main() {
    problemIn();
    solve();
    cout << x << " " << y << endl;
    return 0;
}
 


