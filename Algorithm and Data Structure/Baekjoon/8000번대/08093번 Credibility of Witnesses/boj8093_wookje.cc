#include <cstdio>
#include <vector>
using namespace std;

int n, m, res[3003], chk[3003];
vector<int> gph[3003];

void go(int now, int root) {
    chk[now] |= 2;
    for (int nxt : gph[now]) {
        if (nxt < 0) {
            chk[-nxt] |= 1;
            continue;
        }
        if (chk[nxt] < 2) go(nxt, root);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        gph[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        go(i, i);
        for (int j = 1; j <= n; j++) {
            if (chk[j] == 3) res[i] = 1;
            chk[j] = 0;
        }
    }
    int r = 0;
    for (int i = 1; i <= n; i++) {
        if (res[i]) printf("%d\n", i), r++;
    }
    if (!r) puts("NIKT");
    return 0;
}