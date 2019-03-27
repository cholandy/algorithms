#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int height[5002];
vector<int> adj[5002];
int visit[5002];
bool indegree[5002];
 
int dfs(int here, int cost)
{
    int len = adj[here].size();
 
    for (int i = 0; i < len; i++)
    {
        int there = adj[here][i];
 
        // 이미 there이 방문한 노드면
        if (visit[there] >= 2)
        {
            visit[here] = max(visit[here], visit[there] + 1);
            continue;
        }
 
        int get = 1;
        get += dfs(there, i);
 
        // 이미 here이 방문한 노드면
        if (visit[here] >= 2)
            visit[here] = max(visit[here], get);
        else
            visit[here] = get;    
    }
 
    return visit[here];    
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &height[i]);
        visit[i] = 1;
    }
 
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
 
        // 높이가 낮은 쪽->높은 쪽으로 연결
        // indegree는 진입 노드 개수 카운트
        if (height[a] > height[b])
        {
            adj[b].push_back(a);
            indegree[a] = true;
        }
 
        else
        {
            adj[a].push_back(b);
            indegree[b] = true;
        }
    }
 
    // 진입 노드가 0개라면 시작 노드가 될 수 있다.
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            dfs(i, 1);
 
    for (int i = 1; i <= n; i++)
        printf("%d\n", visit[i]);
 
    return 0;
}