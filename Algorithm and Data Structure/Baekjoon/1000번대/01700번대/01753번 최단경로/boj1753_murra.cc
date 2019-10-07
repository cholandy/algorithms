#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXX 20001

int v, e, k;
int from, to, cost;
vector<pair<int, int>> graph[MAXX];

vector<int> dijkstra(int start, int vertex) {
    vector<int> distance(vertex, INF);  // start ~ 각 vertex 까지의 거리 저장, 초기값 INF
    distance[start] = 0;                // start ~ start = 0

    // 최소 힙 생성 pair<cost, vertex>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        // 이미 더 작을 경우 넘어가자.
        if (distance[currentVertex] < cost) {
            continue;
        }

        int neighborNum = graph[currentVertex].size();
        for (int i = 0; i < neighborNum; i++) {
            int neighbor = graph[currentVertex][i].first;             // to
            int distanceToN = cost + graph[currentVertex][i].second;  // cost

            if (distance[neighbor] > distanceToN) {
                distance[neighbor] = distanceToN;
                pq.push({distanceToN, neighbor});
            }
        }
    }
    return distance;
}

int main() {
    cin >> v >> e >> k;
    for (int i = 0; i < e; i++) {
        cin >> from >> to >> cost;
        // from에서 to로 가는 cost를 저장한다.
        graph[from].push_back({to, cost});
    }
    // 0부터 시작해서 v에 1을 더해줘야 한다.
    vector<int> result = dijkstra(k, v + 1);
    for (int i = 1; i < v + 1; i++) {
        if (result[i] == INF) {
            cout << "INF" << '\n';
        } else {
            cout << result[i] << '\n';
        }
    }
}