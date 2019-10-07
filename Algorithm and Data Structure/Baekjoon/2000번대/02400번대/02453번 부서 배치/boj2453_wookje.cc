#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

struct edg  {
    int idx, type;
};
int flag, chk[10001];
bool dp[5001][10001];
vector<edg> gph[10001];
pair<int, int> res[10001];

void dfs(int now, int prv, int type, int &cnt) {
    if (gph[now].size() == 0) {
        chk[now] = 0;
        cnt--;
        return;
    }

    chk[now] = chk[prv] * type;
    chk[now] == 1 ? res[cnt].fst++ : res[cnt].snd++;

    for (edg nxt : gph[now]) {
        if (flag) return;

        if (!chk[nxt.idx]) {
            dfs(nxt.idx, now, nxt.type, cnt);
        }

        if (chk[nxt.idx] == -chk[now]*nxt.type) {
            flag = 1;
            return;
        }
    }
}

void process() {
    int n, m;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 10000; i++) {
        gph[i].clear();
        chk[i] = res[i].fst = res[i].snd = 0;
    }
    flag = 0;

    scanf("%d %d", &n, &m);
    while (m--) {
        int t, u, v;
        scanf("%d %d %d", &t, &u, &v);
        gph[u].push_back({ v,t });
        gph[v].push_back({ u,t });
    }

    queue<edg> que;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!chk[i]) {
            chk[i] = 1;
            dfs(i, i, 1, ++cnt);
        }
    }

    if (flag) {
        puts("-1");
        return;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j <= n; j++) {
            if (j-res[i].fst >= 0) dp[i][j] |= dp[i-1][j-res[i].fst];
            if (j-res[i].snd >= 0) dp[i][j] |= dp[i-1][j-res[i].snd];
        }
    }

    int mn = 1e9;
    int no = 0;
    for (int i = 1; i <= n; i++) {
        if (!chk[i]) no++;
        if (!dp[cnt][i]) continue;
        if (abs(n/2-i) < abs(n/2-mn)) mn = i;
        if (abs((n+1)/2-i) < abs((n+1)/2-mn)) mn = i;
    }

    //printf("/ %d %d / ", mn, no);

    int a = mn, b = n - mn - no;
    if (a > b) swap(a, b);
    if (a + no <= b) printf("%d\n", b - a - no);
    else printf("%d\n", (no-(b-a))%2);

    /*printf("\n---%d--\n",flag);
    for (int i = 1; i <= cnt; i++) {
        printf("%d: %d %d\n", i, res[i].fst, res[i].snd);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", chk[i]);
    }*/
}

int main() {
    for (int t = 5; t; t--) {
        process();
    }
    return 0;
}