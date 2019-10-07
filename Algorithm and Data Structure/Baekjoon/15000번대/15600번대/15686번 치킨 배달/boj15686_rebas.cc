#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct pos {
    int x, y;
};

int n, m, ans=1e9;
vector<pos> home, chicken;
vector<int> v;

void solve(int idx, int cnt) {
    if (idx > (int)chicken.size()) return;
    if (cnt == m) {
        int sum = 0;
        for (int i=0; i<(int)home.size(); i++) {
            int d = 1e9;
            for (auto j : v) {
                d = min(d, abs(home[i].x-chicken[j].x)+abs(home[i].y-chicken[j].y));
            }
            sum += d;
        }
        ans = min(ans, sum);
        return;
    }
    v.push_back(idx);
    solve(idx+1, cnt+1);
    v.pop_back();
    solve(idx+1, cnt);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int a;
            scanf("%d", &a);
            if (a == 1) home.push_back({i, j});
            else if (a == 2) chicken.push_back({i, j});
        }
    }
    solve(0, 0);
    printf("%d\n", ans);
    return 0;
}


