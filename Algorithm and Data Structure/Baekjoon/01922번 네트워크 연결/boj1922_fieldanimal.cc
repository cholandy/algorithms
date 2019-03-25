#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int visit[1001];
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>> q;//오는비용,노드
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    while (M--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    q.push({ 0,1 });
    int ans = 0;
    while (!q.empty())
    {
        int cost = q.top().first;
        int node = q.top().second;
        q.pop();
        if (visit[node])
            continue;
        visit[node] = 1;
        ans += -cost;
    
        for (pair<int, int> p : adj[node])
        {
            int toCost = p.second;
            int toNode = p.first;
            q.push({ -toCost,toNode });
 
        }
    }
    printf("%d", ans);
}
