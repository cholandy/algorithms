#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int n, m, chk[3003][3003];
vector<int> gph[3003];

void dfs(int now, int num, int cnt) {
    if (cnt == m) {
        puts("YES");
        exit(0);
    }
    for (int nxt : gph[now]) {
        if (chk[now][nxt] == num || chk[nxt][now] == num) continue;
        chk[now][nxt] = chk[nxt][now] = num;
        dfs(nxt, num, cnt+1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        gph[u].push_back(v);
        gph[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        dfs(i, i, 0);
    }

    puts("NO");

    return 0;
}