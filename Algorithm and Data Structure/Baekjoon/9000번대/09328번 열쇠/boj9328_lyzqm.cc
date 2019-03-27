#include <cstdio>

#include <cstring>

#include <algorithm>

#include <vector>

#include <queue>

using namespace std;

int N, M;

int ans;

char map[101][101];

bool visit[101][101];

int dy[] = { -1,0,0,1 };

int dx[] = { 0,1,-1,0 };

vector<char> key;

bool check(int y, int x) {

    if (y < 0 || y >= N || x < 0 || x >= M || visit[y][x]) return true;

    return false;

}

int save(queue<int> &q, int y, int x) {

    int ret = 0;

    if (map[y][x] == '.' && !visit[y][x]) {

        q.push(y*M + x), visit[y][x] = true;

    }

    else if (('a' <= map[y][x] && map[y][x] <= 'z') || (map[y][x] == '$')) {

        ret |= 1;

        if (map[y][x] != '$') key.push_back(map[y][x]);

        else ans++;

        map[y][x] = '.';

    }

    return ret;

}

int bfs() {

    memset(visit, false, sizeof visit);

    queue<int> q;

    int flag = 0;

 

    for (int m = 0;m < M;m++) {

        flag |= save(q, 0, m);

        flag |= save(q, N - 1, m);

    }

    for (int n = 1;n < N - 1;n++) {

        flag |= save(q, n, 0);

        flag |= save(q, n, M - 1);

    }

    if (flag) return true;

    while (!q.empty()) {

        int y = q.front() / M, x = q.front() % M;

        q.pop();

        for (int i = 0;i < 4;i++) {

            int ny = y + dy[i], nx = x + dx[i];

            if (check(ny, nx)) continue;

            if (map[ny][nx] == '.' || ('a' <= map[ny][nx] && map[ny][nx] <= 'z' ) || map[ny][nx] == '$') {

                if (map[ny][nx] != '.') {

                    flag = true;

                    if ('a' <= map[ny][nx] && map[ny][nx] <= 'z') key.push_back(map[ny][nx]);

                    else ans++;

                    map[ny][nx] = '.';

                }

                visit[ny][nx] = true;

                q.push(ny*M + nx);

            }

        }

    }

    return flag;

}

void erase() {

    for (int n = 0;n < N;n++) {

        for (int m = 0;m < M;m++) {

            if ('A' <= map[n][m] && map[n][m] <= 'Z') {

                for (auto &k : key) {

                    if (map[n][m] == k - 'a' + 'A') {

                        map[n][m] = '.';

                        break;

                    }

                }

            }

        }

    }

    key.clear();

}

int main() {

    int T;

    scanf("%d", &T);

    while (T--) {

        char K[33];

        ans = 0;

        key.clear();

        scanf("%d%d", &N, &M);

        for (int n = 0;n < N;n++) scanf("%s", &map[n]);

        scanf("%s", &K);

        if (K[0] != '0') {

            int len = (int)strlen(K);

            for (int n = 0;n < N;n++) {

                for (int m = 0;m < M;m++) {

                    if ('A' <= map[n][m] && map[n][m] <= 'Z') {

                        for (int k = 0;k < len;k++) {

                            if (map[n][m] == K[k] - 'a' + 'A') {

                                map[n][m] = '.';

                                break;

                            }

                        }

                    }

                }

            }

        }

        while (bfs()) {

            erase();

        }

        printf("%d\n", ans);

    }

    return 0;

}