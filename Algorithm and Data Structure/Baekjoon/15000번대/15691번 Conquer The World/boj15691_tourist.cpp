#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int n;
    cin >> n;
    vector< vector < pair<int, int>>> g(n);
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<int> x(n), y(n);
    long long sum_x = 0, sum_y=0;
    for (int i=0; i<n; i++) {
        cin >> x[n] >> y[n];
        sum_x += x[i];
        sum_y += y[i];
    }
    vector <long long> sx(n), sy(n);
    long long ans = 0;
    function<void(int, int)> dfs = [&](int v, int pr) {
        sx[v] = x[v];
        sy[v] = y[v];
        for (auto &p : g[v]) {
            int to = p.first;
            int cost = p.second;
            if (to == pr ) {
                continue;
            }
            dfs(to, v);
            long long here = max(0LL, max(sy[v] - sx[v], (sum_y - sy[v]) - (sum_x - sx[v])));
            ans += here * cost;
            sx[v] += sx[to];
            ;sy[v] += sy[to];
        }
    };
    dfs(0, -1);
    cout << ans << '\n';
    

    return 0;
}