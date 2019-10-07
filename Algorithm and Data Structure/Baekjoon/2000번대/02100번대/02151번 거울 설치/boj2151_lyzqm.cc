#include <cstdio>

#include <queue>

#define INF 888888

using namespace std;

int N, ans = INF;

char map[51][51];

int visit[51][51][4];

bool check(int y, int x){

    if (y < 0 || y >= N || x < 0 || x >= N) return true;

    return false;

}

void bfs(int iy, int ix, int ey, int ex){

    int dy[4] = { -1, 0, 0, 1 }, dx[4] = { 0, 1, -1, 0 };        //상, 우, 좌, 하

    queue<pair<int, pair<int, int>>> q;        //거울 개수,위치, 방향


    for (int i = 0; i < 4; i++){

        if (check(iy + dy[i], ix + dx[i])) continue;

        if (map[iy + dy[i]][ix + dx[i]] != '*'){                //'#'위치에서 네방향 탐색

            q.push({ 0, { (iy + dy[i])*N + ix + dx[i] , i } });

        }

    }

    while (!q.empty()){

        int mir = q.front().first;

        int y = q.front().second.first / N, x = q.front().second.first % N;

        int dir = q.front().second.second;

        q.pop();


        if (y == ey && x == ex){

            ans = ans > mir ? mir : ans;        //도착

            continue;

        }

    

        if (map[y][x] == '!'){

            if (visit[y][x][dir] > mir){

                visit[y][x][dir] = mir;

                if (dir == 0 || dir == 3){                    //방향 상,하 일경우

                    int ly = y + dy[2], lx = x + dx[2];            //좌

                    int ry = y + dy[1], rx = x + dx[1];            //우

                    if (!check(ly, lx) && map[ly][lx] != '*')

                        q.push({ mir + 1, { ly*N + lx, 2 } });

                    if (!check(ry, rx) && map[ry][rx] != '*')

                        q.push({ mir + 1, { ry*N + rx, 1 } });

                }

                else if (dir == 1 || dir == 2){                //방향 좌,우 일경우

                    int uy = y + dy[0], ux = x + dx[0];            //상

                    int doy = y + dy[3], dox = x + dx[3];        //하

                    if (!check(uy, ux) && map[uy][ux] != '*')

                        q.push({ mir + 1, { uy*N + ux, 0 } });

                    if (!check(doy, dox) && map[doy][dox] != '*')

                        q.push({ mir + 1, { doy*N + dox, 3 } });

                }

                int ny = y + dy[dir], nx = x + dx[dir];

                if (!check(ny, nx) && map[ny][nx] != '*'){            //이전 방향대로 이동

                    q.push({ mir, { ny*N + nx, dir } });

                }

            }

            continue;        //뒷부분 넘어감

        }

        int ny = y + dy[dir], nx = x + dx[dir];

        if (!check(ny, nx) && map[ny][nx] != '*'){            //이전 방향대로 이동

            q.push({ mir, { ny*N + nx, dir } });

        }

    }

}

int main(){

    int door[2][2];

    int dcnt = 0;


    scanf("%d", &N);

    for (int n = 0; n < N; n++)

        scanf("%s", map[n]);


    for (int n = 0; n < N; n++){

        for (int m = 0; m < N; m++){

            if (map[n][m] == '#'){

                door[dcnt][0] = n;

                door[dcnt++][1] = m;

            }

            for (int k = 0; k < 4;k++)

                visit[n][m][k] = INF;

        }

    }


    bfs(door[0][0], door[0][1], door[1][0], door[1][1]);

    printf("%d\n", ans);

    return 0;

}
