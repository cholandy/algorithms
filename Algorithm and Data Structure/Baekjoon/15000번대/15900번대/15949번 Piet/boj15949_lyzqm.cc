#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n, m;

char arr[MAXN][MAXN];

int num[MAXN][MAXN];

int dy[] = { -1,0,1,0 };

int dx[] = { 0,1,0,-1 };

// up ,right, down, left

enum dir{

    up = 0, right, down, left 

};

struct Info {

    int y, x;

    int dp, cc;

    Info() {}

    Info(int yy, int xx, int ddp, int ccc) :y(yy), x(xx), dp(ddp), cc(ccc) {}

};

struct Point {

    int y, x;

    Point() {}

    Point(int yy, int xx) :y(yy), x(xx) {}

};

 

 

vector<Point> point[100001];

bool isout(int y, int x) {

    if (y < 0 || y >= n || x < 0 || x >= m) return true;

    return false;

}

void dfs(Point p, int cnt) {

    point[cnt].push_back(p);

    for (int i = 0; i < 4; i++) {

        int ny = p.y + dy[i], nx = p.x + dx[i];

        if (isout(ny, nx) || num[ny][nx] != -1 || arr[p.y][p.x] != arr[ny][nx]) continue;

        num[ny][nx] = cnt;

        dfs(Point(ny, nx), cnt);

    }

}

int main() {

    memset(num, -1, sizeof num);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%s", &arr[i]);

 

    int cnt = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {

        if (arr[i][j] == 'X') continue;

        if (num[i][j] != -1) continue;

        num[i][j] = ++cnt;

        dfs(Point(i,j), cnt);

 

    }

    Info info(0, 0, dir::right, dir::left);

    printf("%c", arr[0][0]);

    while (1) {

        Info cpy = info;

        int g = num[info.y][info.x];

        bool flag = false;

        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 2; j++) {

                if (cpy.dp == dir::up) {

                    if (cpy.cc == dir::left) {

                        sort(point[g].begin(), point[g].end(), [](Point &a, Point &b)->bool {

                            if (a.y == b.y) return a.x < b.x;

                            return a.y < b.y;

                        });

                    }

                    else {

                        sort(point[g].begin(), point[g].end(), [](Point &a, Point &b)->bool {

                            if (a.y == b.y) return a.x > b.x;

                            return a.y < b.y;

                        });

                    }

                }

                else if (cpy.dp == dir::down) {

                    if (cpy.cc == dir::left) {

                        sort(point[g].begin(), point[g].end(), [](Point &a, Point &b)->bool {

                            if (a.y == b.y) return a.x > b.x;

                            return a.y > b.y;

                        });

                    }

                    else {

                        sort(point[g].begin(), point[g].end(), [](Point &a, Point &b)->bool {

                            if (a.y == b.y) return a.x < b.x;

                            return a.y > b.y;

                        });

                    }

                }

                else if (cpy.dp == dir::right) {

                    if (cpy.cc == dir::left) {

                        sort(point[g].begin(), point[g].end(), [](Point &a, Point &b)->bool {

                            if (a.x == b.x) return a.y < b.y;

                            return a.x > b.x;

                        });

                    }

                    else {

                        sort(point[g].begin(), point[g].end(), [](Point &a, Point &b)->bool {

                            if (a.x == b.x) return a.y > b.y;

                            return a.x > b.x;

                        });

                    }

                }

                else if (cpy.dp == dir::left) {

                    if (cpy.cc == dir::left) {

                        sort(point[g].begin(), point[g].end(), [](Point &a, Point &b)->bool {

                            if (a.x == b.x) return a.y > b.y;

                            return a.x < b.x;

                        });

                    }

                    else {

                        sort(point[g].begin(), point[g].end(), [](Point &a, Point &b)->bool {

                            if (a.x == b.x) return a.y < b.y;

                            return a.x < b.x;

                        });

                    }

                }

                Point res = Point(point[g][0].y + dy[cpy.dp], point[g][0].x + dx[cpy.dp]);

                if (!isout(res.y, res.x) && arr[res.y][res.x] != 'X') {

                    printf("%c", arr[res.y][res.x]);

                    flag = true;

                    info.y = res.y, info.x = res.x;

                    info.dp = cpy.dp; info.cc = cpy.cc;

                    break;

                }

                if(!j) cpy.cc += 2; cpy.cc %= 4;

            }

            if (flag) break;

            cpy.dp += 1; cpy.dp %= 4;

        }

        if (!flag) break;

    }

        

    return 0;

}
