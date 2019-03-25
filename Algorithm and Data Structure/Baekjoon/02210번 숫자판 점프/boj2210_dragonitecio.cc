/*
1951 시작합니다.
 
서로 다른 여섯 자리의 수들의 개수를 구하는 프로그램
visit 로 갔던 숫자는 체크하지 않도록 합니다.
0 0 0 1 2 3 이면 6차원로 만들어볼까요?
depth 를 6으로 설정하도로 하고,
 
각 자리에서 시작하도록 하겠습니다.
숫자를 바로 만들어서 vist 체크하도록 하겠습니다.
*/
 
#include <iostream>
#include <algorithm>
using namespace std;
 
#define SIZE 5
int map[SIZE][SIZE];
int ans;
int visit[1000000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dataArr[6];
int val;
 
void problemIn() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }
}
 
void dfs(int depth, int x, int y) {
    if (depth == 6) {
        val = 0;
        for (int i = 0; i < 6; i++) {
            val += dataArr[i] * pow(10, 5 - i);
        }
        if (visit[val] == 0) {
            visit[val] = 1;
            ans++;
        }
        return;
    }
 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        dataArr[depth] = map[nx][ny];
        dfs(depth + 1, nx, ny);
        dataArr[depth] = 0;
    }
}
 
void solve() {
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dataArr[0] = map[i][j];
            dfs(1, i, j);
            dataArr[0] = 0;
        }
    }
}
 
int main() {
    problemIn();
    solve();
    cout << ans << endl;
    return 0;
}
