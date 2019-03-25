#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
 
using namespace std;
 
const int INF = 987654321;
const int MAX_V = 500;
const int S = MAX_V - 2;
const int T = MAX_V - 1;
const int JOB = 70;
 
int table[4][4] = {
    0,0,0,0,
    4,3,2,1,
    8,7,6,5,
    12,11,10,9
};
 
int maxCost[150];
 
struct Edge {
    int v, cost, capacity, flow, rev;
    Edge(int v, int cost, int c, int f, int rev)
        :v(v), cost(cost), capacity(c), flow(f), rev(rev) {}
};
 
vector<Edge> adj[MAX_V];
 
void addEdge(int here, int next, int cost, int cap)
{
    adj[here].emplace_back(next, cost, cap, 0, adj[next].size());
    adj[next].emplace_back(here, -cost, 0, 0, adj[here].size() - 1);
}
 
int main()
{
    int n, m;
 
    // 사람 :: 1~m, 사람 dual :: 1+m ~ m+m
    // 직업 :: 1+JOB ~ 1+n+JOB 직업 dual :: 1+n+JOB~n+n+JOB
    while (1)
    {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
            break;
 
        for (int i = 0; i < MAX_V; i++)
            adj[i].clear();
 
        memset(maxCost, 0, sizeof(maxCost));
 
        // Source에서 사람 관계
        for (int i = 1; i <= m; i++)
            addEdge(S, i, 0, 1);
 
        for (int i = 0; i < n; i++)
            scanf("%d", &maxCost[i]);
                
        // 직업에서 싱크 관계
        for (int j = 1 + JOB; j <= n + JOB; j++)
            addEdge(j, T, 0, maxCost[j - JOB - 1]);
 
        // 사람에서 직업 관계
        for (int i = 1; i <= m; i++)
        {
            int grade;
            scanf("%d", &grade);
            for (int j = 0; j < 4; j++)
            {
                int val;
                scanf("%d", &val);
                addEdge(i, val + 1 + JOB, -table[grade][j], 1);
            }
        }
        int result = 0;
        int cnt = 0;
        
        while (1)
        {
            int vPrev[MAX_V], ePrev[MAX_V], dist[MAX_V];
            bool inQ[MAX_V] = { 0 };
 
            queue<int> q;
            fill(vPrev, vPrev + MAX_V, -1);
            fill(ePrev, ePrev + MAX_V, -1);
            fill(dist, dist + MAX_V, INF);
 
            dist[S] = 0;
            inQ[S] = true;
 
            q.push(S);
 
            while (!q.empty())
            {
                int here = q.front();
                q.pop();
                inQ[here] = false;
 
                for (int i = 0; i < adj[here].size(); i++)
                {
                    int next = adj[here][i].v;
                    int c = adj[here][i].capacity;
                    int f = adj[here][i].flow;
                    int d = adj[here][i].cost;
 
                    if (c - f > 0 && dist[next] > dist[here] + d)
                    {
                        dist[next] = dist[here] + d;
                        vPrev[next] = here;
                        ePrev[next] = i;
 
                        if (!inQ[next])
                        {
                            q.push(next);
                            inQ[next] = true;
                        }
                    }
                }
            }
            if (vPrev[T] == -1)
                break;
 
            int flow = INF;
            for (int i = T; i != S; i = vPrev[i])
            {
                int prev = vPrev[i];
                int idx = ePrev[i];
                flow = min(flow, adj[prev][idx].capacity - adj[prev][idx].flow);
            }
 
            for (int i = T; i != S; i = vPrev[i])
            {
                int prev = vPrev[i];
                int idx = ePrev[i];
 
                result += adj[prev][idx].cost * flow;
 
                adj[prev][idx].flow += flow;
                adj[i][adj[prev][idx].rev].flow -= flow;
            }
            cnt += flow;
        }
        printf("%d\n", -result);
    }
    return 0;
}