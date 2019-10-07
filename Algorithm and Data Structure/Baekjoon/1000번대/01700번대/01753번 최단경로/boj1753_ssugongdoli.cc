#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
 
using namespace std;
 
const int INF = 0x3f3f3f3f;
 
vector<vector<pair<int, int>>> map;
vector<bool> visit;
vector<int> ans;
priority_queue<pair<int, int>> pq;
 
int main()
{
    int v, e;
    int start;
    scanf("%d %d %d", &v, &e, &start);
    int from, to, cost;
    map.resize(v + 1);
    ans.resize(v + 1);
    for (int i = 0; i < v + 1; i++)ans[i] = INF;
 
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &from, &to, &cost);
        
        map[from].push_back(make_pair(to, cost));
    }
 
    pq.push(make_pair(0, start));
    ans[start] = 0;
 
    while (!pq.empty())
    {
        pair<int, int> now = pq.top(); pq.pop();
        now.first *= -1;
        if (now.first > ans[now.second])continue;
        for (int i = 0; i < map[now.second].size(); i++)
        {
            if (ans[map[now.second][i].first] > ans[now.second] + map[now.second][i].second)
            {
                ans[map[now.second][i].first] = ans[now.second] + map[now.second][i].second;
                pq.push(make_pair(-map[now.second][i].second, map[now.second][i].first));
            }
        }
    }
 
    for (int i = 1; i <= v; i++)
    {
        if (ans[i] == INF)
        {
            printf("INF\n");
        }
        else
        {
            printf("%d\n", ans[i]);
        }
    }
 
    return 0;
}
