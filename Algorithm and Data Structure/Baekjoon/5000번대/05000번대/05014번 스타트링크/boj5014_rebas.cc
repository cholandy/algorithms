#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int F, S, G, U, D;
int dist[1000001];

void bfs() {
    queue<int> q;
    q.push(S);
    dist[S] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == G) {
            printf("%d\n", dist[x]);
            return;
        }
        for (int nx : {x+U, x-D}) {
            if (nx < 1 || nx > F || dist[nx] >= 0) continue;
            q.push(nx);
            dist[nx] = dist[x]+1;
        }
    }
    printf("use the stairs\n");
}

int main() {
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    memset(dist, -1, sizeof(dist));
    bfs();
    return 0;
}


출처: https://rebas.kr/777?category=766915 [PROJECT REBAS]