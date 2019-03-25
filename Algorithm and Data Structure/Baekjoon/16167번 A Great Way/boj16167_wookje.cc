#include <cstdio>
#include <queue>
#include <vector>
#define fst first
#define snd second
using namespace std;

int n, m;
struct abc {
    int idx, cst;
};
vector<abc> gph[101];
pair<int, int> dp[101];

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        if (e > 10) c += ((e-10)*d);
        gph[a].push_back({ b,c });
    }
    for (int i = 0; i <= n; i++) dp[i].fst = dp[i].snd = 1e9;
    queue<int> que;
    que.push(1);
    dp[1].fst = 0; dp[1].snd = 1;
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (abc nxt : gph[now]) {
            if (dp[nxt.idx].fst == dp[now].fst + nxt.cst) {
                if (dp[nxt.idx].snd > dp[now].snd + 1) {
                    dp[nxt.idx].snd = dp[now].snd + 1;
                    que.push(nxt.idx);
                }
            }
            if (dp[nxt.idx].fst > dp[now].fst + nxt.cst) {
                dp[nxt.idx].fst = dp[now].fst + nxt.cst;
                dp[nxt.idx].snd = dp[now].snd + 1;
                que.push(nxt.idx);
            }
        }
    }
    if (dp[n].fst == 1e9) {
        return !printf("It is not a great way.");
    }
    printf("%d %d\n", dp[n].fst, dp[n].snd);
    return 0;
}