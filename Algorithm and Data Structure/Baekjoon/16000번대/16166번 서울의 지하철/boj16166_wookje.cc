#include <cstdio>
#include <queue>
#include <map>
using namespace std;

int n, en;
struct abc {
    int idx, hosun, cnt;
    bool operator <(abc a)const {
        return cnt > a.cnt;
    }
};
map<pair<int, int>, int> cnt;
map<int, int> subway;

int main() {
    scanf("%d", &n);
    for (int i = 1, k; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 0, x; j < k; j++) {
            scanf("%d", &x);
            subway[x] |= (1<<i);
        }
    }
    scanf("%d", &en);

    for (auto it : subway) {
        for (int i = 1; i <= n; i++) {
            cnt[{ it.first,i }] = 1e9;
        }
    }

    priority_queue<abc> pq;
    for (int i = 1; i <= n; i++) {
        if (subway[0] & (1<<i)) {
            pq.push({ 0,i,0 });
            cnt[{ 0,i }] = 0;
        }
    }
    while (!pq.empty()) {
        abc now = pq.top();
        pq.pop();
        int num = subway[now.idx];
        for (int i = 1; i <= n; i++) {
            if (!(num & (1<<i))) continue;
            for (auto nxt : subway) {
                if (!(nxt.second & (1<<i))) continue;
                if (cnt[{ nxt.first,i }] > cnt[{ now.idx,now.hosun }] + (now.hosun != i)) {
                    cnt[{ nxt.first,i }] = cnt[{ now.idx,now.hosun }] + (now.hosun != i);
                    pq.push({ nxt.first,i,cnt[{ nxt.first,i }] });
                }
            }
        }
    }

    int dap = 1e9;
    for (int i = 1; i <= n; i++) {
        if (dap > cnt[{ en,i }]) dap = cnt[{ en,i }];
    }
    printf("%d\n", dap == 1e9 ? -1 : dap);

    return 0;
}