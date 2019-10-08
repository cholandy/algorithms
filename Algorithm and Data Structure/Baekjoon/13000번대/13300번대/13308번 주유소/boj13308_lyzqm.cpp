#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

#define INF 987654321
typedef pair<int, int> P;
typedef pair<long long, P> TP;

int N, M;
int cost[2501];
vector<pair<int, int>> adj[2501];

long long solve(int start, int end) {
    vector<vector<long long>> dist(2502, vector<long long>(2502, INF));
    priority_queue<TP, vector<TP>, greater<TP>> pq;
    pq.push({ 0,{ cost[start],start } });        // dist, standard, next
    while (!pq.empty()) {
        int here = pq.top().second.second;
        int std = pq.top().second.first;
        long long d = pq.top().first;

        pq.pop();
        if (here == end) return d;
        if (dist[here][std] != INF) continue;
        dist[here][std] = d;
        for (auto n : adj[here]) {
            int next = n.second;
            long long ndist = d + std*n.first;
            if (dist[next][min(std, cost[next])] == INF) {
                pq.push({ ndist,{ min(std,cost[next]), next } });
            }
        }
    }
    return -1;
}
int main() {
    scanf("%d%d", &N, &M);
    for (int n = 1;n <= N;n++) scanf("%d", &cost[n]);
    for (int m = 0;m < M;m++) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        adj[u].push_back({ d,v });
        adj[v].push_back({ d,u });
    }
    printf("%lld\n", solve(1, N));
    return 0;
}
