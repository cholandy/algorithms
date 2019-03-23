#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
 
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
 
using namespace std;
 
const int INF = 987654321;
const int pig = 200;
 
int c[1500][1500], f[1500][1500];
vector<int> adj[1500];
 
int s = 0, t = 1300;
 
vector<int> share[1500];
 
int main()
{
    fastio();
 
    int n, m;
    cin >> m >> n;
 
    // source :: 0 sink :: 1300
    for (int i = 1; i <= m; i++)
    {
        int val;
        cin >> val;
 
        c[pig + i][t] = val;
        adj[pig + i].push_back(t);
        adj[t].push_back(pig + i);
 
    }
 
 
    for (int i = 1; i <= n; i++)
    {
        int key;
        cin >> key;
 
        for (int j = 0; j < key; j++)
        {
            int val;
            cin >> val;
 
            share[val].push_back(i);
 
            c[i][pig + val] = INF;
            adj[i].push_back(pig + val);
            adj[pig + val].push_back(i);
        }
 
        int val;
        cin >> val;
 
        c[0][i] = val;
        
        adj[0].push_back(i);
        adj[i].push_back(0);
    }
 
    for (int i = 1; i <= m; i++)
    {
        if (!share[i].size())
            continue;
 
        for (int j = 0; j < share[i].size() - 1; j++)
        {
            int here = share[i][j];
            for (int k = j + 1; k < share[i].size(); k++)
            {
                int next = share[i][k];
 
                c[next][here] = INF;
 
                adj[here].push_back(next);
                adj[next].push_back(here);
            }
        }
    }
 
    int totalFlow = 0;
 
    while (1)
    {
        vector<int> prev(1500, -1);
 
        queue<int> q;
        q.push(s);
 
        while (!q.empty() && prev[t] == -1)
        {
            int here = q.front();
            q.pop();
 
            for (int i = 0; i < adj[here].size(); i++)
            {
                int next = adj[here][i];
                if (prev[next] != -1)
                    continue;
 
                if (c[here][next] - f[here][next] > 0)
                {
                    q.push(next);
                    prev[next] = here;
                }
            }
        }
 
        if (prev[t] == -1)
            break;
 
        int flow = INF;
 
        for (int i = t; i != s; i = prev[i])
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
 
        for (int i = t; i != s; i = prev[i])
        {
        
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        totalFlow += flow;
    }
 
    cout << totalFlow;
 
    return 0;
}