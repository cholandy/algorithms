#include <stdio.h>
int edge[1010][1010];
int visited[1010];
int u, v;
int N, M;

void dfs(int cur) {
    visited[cur] = 1;
    printf("%d ", cur);
    for (int i = 1; i <= N; i++) {
        if (visited[i]!=0 || edge[cur][i] == 0 ) continue; // already visited or not connected.
        dfs(i);
    }
}

int main() 
{
    scanf("%d %d", &N,&M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        edge[u][v] = 1; // u -> v edge connect
    }
    dfs(1);
}