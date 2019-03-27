#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
 
using namespace std;
 
const int MAX_V = 500;
const int S = MAX_V - 2;
const int T = MAX_V - 1;
const int sero = 200;
const int INF = 987654321;
 
typedef pair<int, int> pii;
vector<pair< pair<pii, pii>, pii> > width;
vector<pair<pii, int> > height;
 
vector<int> adj[MAX_V];
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int d[MAX_V][MAX_V];
 
int main()
{
    int tc;
    scanf("%d", &tc);
 
    while (tc--)
    {
        for (int i = 0; i < MAX_V; i++)
            adj[i].clear();
        width.clear();
        height.clear();
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(d, 0, sizeof(d));
 
        int n, m;
        scanf("%d %d", &n, &m);
 
        // S :: 498   T :: 499   가로 :: 0 ~ 199   세로 :: 200 ~ 399
        for (int i = 0; i < n; i++)
        {
            c[S][i] = 1;
            d[S][i] = 0;
            d[i][S] = 0;
 
            adj[S].push_back(i);
            adj[i].push_back(S);
        }
 
        for (int i = 0; i < m; i++)
        {
            c[i + sero][T] = 1;
            d[i + sero][T] = 0;
            d[T][i + sero] = 0;
 
            adj[i + sero].push_back(T);
            adj[T].push_back(i + sero);
        }
 
        // 가로
        for (int i = 0; i < n; i++)
        {
            int x1, y1, x2, y2, w;
            scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &w);
 
            if (x1 > x2)
                swap(x1, x2);
            
            width.push_back({ {{x1,y1},{x2,y2}}, {i,w} });
        }
 
        // 세로
        for (int i = 0; i < m; i++)
        {
            int x1, y1, x2, y2, w;
            scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &w);
 
            if (y1 > y2)
                swap(y1, y2);
            
            for (int j = 0; j < width.size(); j++)
            {
                int gx1 = width[j].first.first.first;
                int gy1 = width[j].first.first.second;
                int gx2 = width[j].first.second.first;
                int gy2 = width[j].first.second.second;
                int gidx = width[j].second.first;
                int gw = width[j].second.second;
 
                // 선분이 겹쳐져 있다면
                if(gx1 <= x1 && x1 <= gx2)
                    if (y1 <= gy1 && gy1 <= y2)
                    {
                        c[gidx][i + sero] = 1;
                        d[gidx][i + sero] = -gw * w;
                        d[i + sero][gidx] = gw * w;
                        adj[gidx].push_back(i + sero);
                        adj[i + sero].push_back(gidx);
                    }
            }
 
        }
 
 
        int result = 0;
        int cnt = 0;
 
        while (1)
        {
            int prev[MAX_V], dist[MAX_V];
            bool inQ[MAX_V] = { 0 };
 
            queue<int> q;
            fill(prev, prev + MAX_V, -1);
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
                    int next = adj[here][i];
 
                    if (c[here][next] - f[here][next] > 0 && dist[next] > dist[here] + d[here][next])
                    {
                        dist[next] = dist[here] + d[here][next];
                        prev[next] = here;
 
                        if (!inQ[next])
                        {
                            q.push(next);
                            inQ[next] = true;
                        }
                    }
 
                }
            }
 
            if (prev[T] == -1)
                break;
 
            int flow = INF;
 
            for (int i = T; i != S; i = prev[i])
                flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
            
            for (int i = T; i != S; i = prev[i])
            {
                result += flow * d[prev[i]][i];
                f[prev[i]][i] += flow;
                f[i][prev[i]] -= flow;
            }
 
            cnt+=flow;
        }
 
        printf("%d %d\n", cnt, -result);
 
    }
    return 0;
}
