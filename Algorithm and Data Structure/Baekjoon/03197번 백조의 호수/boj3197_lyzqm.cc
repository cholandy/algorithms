#include <cstdio>
#include <queue>

using namespace std;

int N, M;
char map[1500][1500];
int L[2][2], lcnt = 0;
int wvisit[1500][1500], svisit[1500][1500];

queue<pair<int, int>> water, nwater;
queue<pair<int, int>> swan, nswan;

int main(){
    int dy[4] = { -1, 0, 0, 1 }, dx[4] = { 0, 1, -1, 0 };
    scanf("%d%d", &N, &M);
    for (int n = 0; n < N; n++){
        for (int m = 0; m < M; m++){
            scanf(" %1c", &map[n][m]);
            if (map[n][m] == 'L'){
                L[lcnt][0] = n;
                L[lcnt++][1] = m;
                map[n][m] = '.';
            }
            if (map[n][m] == '.'){
                water.push({ n, m });
                wvisit[n][m] = 1;
            }
        }
    }

    swan.push({ L[0][0], L[0][1] });
    svisit[L[0][0]][L[0][1]] = 1;
    int ans = 0;
    for (ans = 0; !svisit[L[1][0]][L[1][1]]; ans++){
        for (; !water.empty(); water.pop()) nwater.push(water.front());
        for (; !swan.empty(); swan.pop()) nswan.push(swan.front());
        for (; !nwater.empty(); nwater.pop()){
            int y = nwater.front().first, x = nwater.front().second;
            map[y][x] = '.';
            for (int i = 0; i < 4; i++){
                int ny = y + dy[i], nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || wvisit[ny][nx]) continue;
                wvisit[ny][nx] = 1;
                water.push({ ny, nx });
            }
        }

        for (; !nswan.empty(); nswan.pop()){
            int y = nswan.front().first, x = nswan.front().second;
            for (int i = 0; i < 4; i++){
                int ny = y + dy[i], nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || svisit[ny][nx]) continue;
                svisit[ny][nx] = 1;
                if (map[ny][nx] == '.')    nswan.push({ ny, nx });
                else if (map[ny][nx] == 'X') swan.push({ ny, nx });
            }
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}
