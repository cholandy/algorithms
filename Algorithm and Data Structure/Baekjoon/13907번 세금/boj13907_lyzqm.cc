#include <cstdio>

#include <vector>

#include <queue>

#include <algorithm>

#include <functional>

using namespace std;

#define INF 987654321987654321

typedef long long ll;

typedef pair<pair<ll,int>, int> P;        //dist, edge cnt, vertex

#define mp(a,b) make_pair(a,b)

#define mt(a,b,c) mp(mp(a,b),c)

int N, M, K;

int S, E;

vector<pair<int, int>> adj[1001];

ll dist[1001][1001];

void dijkstra(ll &first) {

    for (int n = 1;n <= N;n++)

        for (int m = 0;m < 1001;m++) dist[n][m] = INF;


    priority_queue<P, vector<P>, greater<P>> pq;


    dist[S][0] = 0;

    pq.push(mt(0, 0, S));

    while (!pq.empty()) {

        int here = pq.top().second;

        int cnt = pq.top().first.second;

        ll cost = pq.top().first.first;

        pq.pop();


        bool find = false;

        for (int i = 0;i < cnt;i++) {

            if (dist[here][i] < cost) {

                find = true;

                break;

            }

        }

        if (find || dist[here][cnt] < cost) continue;

        if (here == E) {

            first = min(first, dist[here][cnt]);

            continue;

        }

        for (auto n : adj[here]) {

            int next = n.second;

            ll ncost = (ll)n.first;

            if (cnt + 1 <= N && dist[next][cnt + 1] > dist[here][cnt] + ncost) {

                dist[next][cnt + 1] = dist[here][cnt] + ncost;

                pq.push(mt(dist[next][cnt + 1], cnt + 1, next));

            }

        }

    }

}

int main() {

    scanf("%d%d%d", &N, &M, &K);

    scanf("%d%d", &S, &E);

    for (int m = 0;m < M;m++) {

        int u, v, d;

        scanf("%d%d%d", &u, &v, &d);

        adj[u].push_back({ d,v });

        adj[v].push_back({ d,u });

    }

    ll first = INF;

    dijkstra(first);

    printf("%lld\n", first);

    vector<pair<ll,ll>> re;

    for (int e = 1;e <= N;e++) {

        if (dist[E][e] != INF) {

            re.push_back(mp(dist[E][e], (ll)e));

        }

    }

    ll sum_tax = 0, tax;

    for (int k = 0;k < K;k++) {

        scanf("%lld", &tax);

        sum_tax += tax;

        ll ret = INF;

        for (auto n : re) {

            ret = min(ret, n.first + n.second*sum_tax);

        }

        printf("%lld\n", ret);

    }

    return 0;

}
