#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int n_ = 2e5 + 2;
const int k_ = 1e6 + 2;
const int inf = 0x3f3f3f3f;

int n, k, siz[n_], vst[n_], chk[k_];
struct edg { int idx, dst; };
vector<edg> gph[n_];

int get_size(int now, int prv) {
    siz[now] = 1;
    for (edg nxt : gph[now]) {
        if (nxt.idx == prv || vst[nxt.idx]) {
            continue;
        }
        siz[now] += get_size(nxt.idx, now);
    }
    return siz[now];
}

int get_cent(int now, int prv, int cap) {
    for (edg nxt : gph[now]) {
        if (nxt.idx == prv || vst[nxt.idx]) {
            continue;
        }
        if (siz[nxt.idx] > cap) {
            return get_cent(nxt.idx, now, cap);
        }
    }
    return now;
}

int calc_ans(int now, int prv, int dst, int dph) {
    int ret = inf;
    if (dst > k) {
        return ret;
    }
    if (chk[k-dst] != inf) {
        ret = chk[k-dst]+dph;
    }
    for (edg nxt : gph[now]) {
        if (vst[nxt.idx] || nxt.idx == prv) {
            continue;
        }
        ret = min(ret, calc_ans(nxt.idx, now, dst+nxt.dst, dph+1));
    }
    return ret;
}

void update_chk(int now, int prv, int dst, int dph) {
    if (dst > k) {
        return;
    }
    chk[dst] = min(chk[dst], dph);
    vec.push_back(dst);
    for (edg nxt : gph[now]) {
        if (vst[nxt.idx] || nxt.idx == prv) {
            continue;
        }
        update_chk(nxt.idx, now, dst+nxt.dst, dph+1);
    }
}

int go(int now) {
    int cap = get_size(now, -1);
    int cent = get_cent(now, -1, cap/2);
    int ret = inf;
    
    for (int it : vec) {
        chk[it] = inf;
    }
    vec.clear();

    vst[cent] = 1;
    chk[0] = 0;

    for (edg nxt : gph[cent]) {
        if (!vst[nxt.idx]) {
            ret = min(ret, calc_ans(nxt.idx, cent, nxt.dst, 1));
            update_chk(nxt.idx, cent, nxt.dst, 1);
        }
    }

    for (edg nxt : gph[cent]) {
        if (vst[nxt.idx]) {
            continue;
        }
        ret = min(ret, go(nxt.idx));
    }

    return ret;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        gph[u].push_back({ v,w });
        gph[v].push_back({ u,w });
    }

    fill(chk, chk+k+1, inf);
    int res = go(0);
    printf("%d\n", res != inf ? res : -1);

    return 0;
}