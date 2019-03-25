#include <cstdio>
#include <queue>
using namespace std;

int p, n, res, dst, c[1000002];
struct abc {
    int idx, cst;
    bool operator <(abc a)const { return cst>a.cst; }
};
priority_queue<abc> pq;

int main() {
    scanf("%d %d", &p, &n);
    for (int i = 1, x, d; i <= n; i++) {
        scanf("%d %d", &x, &d);
        c[dst] = x; dst += d;
    }
    for (int i = 0; i < dst; i++) {
        if (c[i]) pq.push({ i,c[i] });
        while (!pq.empty() && pq.top().idx <= i-p) pq.pop();
        res += pq.top().cst;
    }
    printf("%d\n", res);
    return 0;
}