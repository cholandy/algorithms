#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
 
using namespace std;
 
typedef pair<double, double> pdd;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
 
const double INF = 987654321.0;
 
double getDist(pdd s, pdd e)
{
    return sqrt((e.first - s.first) * (e.first - s.first) 
        + (e.second - s.second) * (e.second - s.second));
}
 
vector<pid> adj[111];
pdd arr[111];
double dist[111];
 
int main()
{
    pdd start, end;
    scanf("%lf %lf", &start.first, &start.second);
    scanf("%lf %lf", &end.first, &end.second);
 
    int n;
    scanf("%d", &n);
 
    for (int i = 1; i <= n; i++)
        scanf("%lf %lf", &arr[i].first, &arr[i].second);
 
    // 시작점에서 각 대포로의 그래프 형성
    for (int i = 1; i <= n; i++)
        adj[0].push_back({ i, getDist(start, arr[i]) / 5.0 });
 
    // 시작점에서 끝점으로의 그래프 형성
    adj[0].push_back({ n + 1, getDist(start, end) / 5.0 });
 
    // 각 대포에서 끝점으로의 그래프 형성
    for (int i = 1; i <= n; i++)
    {
        adj[i].push_back({ n + 1, getDist(arr[i], end) / 5.0 });
        adj[i].push_back({ n + 1, 2.0 + fabs(getDist(arr[i], end) - 50.0) / 5.0 });
    }
 
    // 각 대포끼리의 그래프 형성
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
            {
                adj[i].push_back({ j, getDist(arr[i], arr[j]) / 5.0 });
                adj[i].push_back({ j, 2.0 + fabs(getDist(arr[i], arr[j]) - 50.0) / 5.0 });
            }
 
    // Priority Queue Dijkstra
    for (int i = 0; i <= n + 1; i++)
        dist[i] = INF;
 
    priority_queue<pdi, vector<pdi>, greater<pdi> > pq;
 
    pq.push({ 0.0, 0 });
 
    while (!pq.empty())
    {
        int here = pq.top().second;
        double hereCost = pq.top().first;
 
        pq.pop();
 
        if (hereCost > dist[here])
            continue;
 
 
        int len = adj[here].size();
        for (int i = 0; i < len; i++)
        {
            int next = adj[here][i].first;
            double nextCost = adj[here][i].second + hereCost;
 
            if (nextCost < dist[next])
            {
                dist[next] = nextCost;
                pq.push({ nextCost, next });
            }
        }
    }
 
    printf("%.6lf", dist[n + 1]);
 
    return 0;
}