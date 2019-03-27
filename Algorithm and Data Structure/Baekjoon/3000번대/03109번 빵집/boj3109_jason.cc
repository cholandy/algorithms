#include <cstdio>
#include <algorithm>
using namespace std;
int r, c, visited[10002][502], res;
char a[10002][502];
int dx[] = { -1,0,1 };
int dy[] = { 1,1,1 };
int dfs(int x, int y) {
    visited[x][y] = 1;
    if (y == c - 1)return 1;
    for (int i = 0; i < 3; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (!visited[cx][cy] && a[cx][cy] == '.') {
            int v = dfs(cx, cy);
            if (v)return v;
        }
    }
    return 0;
}
int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        getchar();
        for (int j = 0; j < c; j++)
            scanf("%c", &a[i][j]);
    }
    for (int i = 0; i < r; i++)
        res += dfs(i, 0);
    printf("%d\n", res);
    return 0;
}


