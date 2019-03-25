#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int A, B, C, D;
bool check[1000][1000];

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(A, B));
    check[A][B] = true;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        int z = D-x-y;
        if (x == y && y == z) {
            printf("1\n");
            return;
        }
        int nx[] = {x, x, y}, ny[] = {y, z, z};
        for (int i=0; i<3; i++) {
            int a = nx[i], b = ny[i];
            if (a < b) b -= a, a += a;
            else if (a > b) a -= b, b += b;
            else continue;
            int c = D-a-b;
            int X = min(min(a, b), c);
            int Y = max(max(a, b), c);
            if (!check[X][Y]) {
                q.push(make_pair(X, Y));
                check[X][Y] = true;
            }
        }
    }
    printf("0\n");
}

void solve() {
    if (D%3) {
        printf("0\n");
        return;
    } else bfs();
}

int main() {
    scanf("%d %d %d", &A, &B, &C);
    D = A+B+C;
    solve();
    return 0;
}


