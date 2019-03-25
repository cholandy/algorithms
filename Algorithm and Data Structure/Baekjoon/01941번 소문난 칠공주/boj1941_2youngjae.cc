#include <stdio.h>
#include <memory.h>
using namespace std;
 
int map[25];
bool visited[25];
bool check[5][5];
int scnt, ycnt, res;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
 
void isOK(int x,int y) {
    check[x][y] = true;
    if (map[5 * x + y] == 'Y') {
        ycnt++;
    }
    else {
        scnt++;
    }
 
    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];
        if (ax >= 0 && ay >= 0 && ax < 5 && ay < 5) {
            if (visited[5 * ax + ay] && !check[ax][ay]) {
                isOK(ax, ay);
            }
        }
    }
}
 
void isCheck() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (visited[5 * i + j]) {
                isOK(i, j);
                return;
            }
        }
    }
}
 
void solve(int v,int cnt) {
    visited[v] = true;
 
    if (cnt == 7) {
        scnt = 0;
        ycnt = 0;
        memset(check, 0, sizeof(check));
        isCheck();
        if (scnt + ycnt == 7) {
            if (scnt > 3) {
                res++;
            }
        }
    }
    else {
        for (int i = v + 1; i < 25; i++) {
            solve(i, cnt + 1);
        }
    }
 
    visited[v] = false;
}
 
int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[5 * i + j] = getchar();
        }
        getchar();
    }
    
    for (int i = 0; i < 19; i++) {
        solve(i, 1);
    }
 
    printf("%d\n", res);
}
