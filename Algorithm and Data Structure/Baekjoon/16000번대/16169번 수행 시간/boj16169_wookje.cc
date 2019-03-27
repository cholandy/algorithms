#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, dap, l[101], t[101], d[101], r[101];
struct edg { int idx, dst; };
vector<edg> gph[101];

void go(int now) {
    dap = max(dap, r[now]);
    for (edg nxt : gph[now]) {
        r[nxt.idx] = max(r[nxt.idx], r[now] + t[nxt.idx] + nxt.dst);
        if (!(--d[nxt.idx])) go(nxt.idx);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &t[i]);
        r[i] = t[i];
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (l[i]+1 == l[j]) {
            gph[i].push_back({ j,(i-j)*(i-j) });
            d[j]++;
        }
    }

    for (int i = 1; i <= n; i++) if (!d[i]) go(i);
    printf("%d\n", dap);
    
    return 0;
}