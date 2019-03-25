#include <iostream>
#include <algorithm>
using namespace std;
 
int n, m;
int map[502][502];
int d[502][502];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
 
void dfs(int x, int y) {
    d[x][y] = 1;
 
    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];
 
        if (map[ax][ay] == 0) continue;
 
        /*
        d[ax][ay]에 기록된 값이 d[ax][ay]에서 
        탐색 했을때의 최대값이고,
        map[x][y] < map[ax][ay] 라는건
        현재지점에서 다음지점으로 갈 수 있다는 얘기이므로
        +1 해줘서 비교해준다.
        */
        if (map[x][y] < map[ax][ay]) {
            //한번도 방문하지 않은 곳이면 dfs 수행
            if (d[ax][ay] == 0) dfs(ax, ay);
 
            d[x][y] = max(d[x][y], d[ax][ay] + 1);
        }
    }
}
 
int get_result() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, d[i][j]);
        }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == 0) {
                dfs(i, j);
            }
        }
    }
 
    cout << get_result() << endl;
    return 0;
}
 