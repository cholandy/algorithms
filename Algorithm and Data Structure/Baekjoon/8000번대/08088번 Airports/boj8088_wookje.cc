#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int n;
priority_queue<pii, vector<pii>, less<pii> > pq;
vector<int> r[501];
vector<pii> tmp;
int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x); pq.push({ x,i });
    }
    while (!pq.empty()) {
        auto a = pq.top(); pq.pop();
        while (a.first--) {
            auto b = pq.top(); pq.pop();
            r[a.second].push_back(b.second);
            if (--b.first) tmp.push_back(b);
        }
        for (pii it : tmp) pq.push(it);
        tmp.clear();
    }
    for (int i = 1; i <= n; i++) {
        for (int j : r[i]) printf("%d %d\n", i, j);
    }
    return 0;
}