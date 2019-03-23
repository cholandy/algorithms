#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
 
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
 
using namespace std;
 
const int INF = 987654321;
const int FOOD = 250;
 
int c[502][502];
int f[502][502];
 
vector<int> adj[502];
 
int S = 0, T = 500;
int main()
{
    int n, k, d;
    cin >> n >> k >> d;
 
    for (int i = 1; i <= n; i++)
    {
        c[S][i] = k;
 
        adj[S].push_back(i);
        adj[i].push_back(S);
    }
 
    for (int i = 1; i <= d; i++)
    {
        int val;
        cin >> val;
 
        c[i + FOOD][T] = val;
        adj[i + FOOD].push_back(T);
        adj[T].push_back(i + FOOD);
    }
 
    for (int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;
 
        for (int j = 0; j < cnt; j++)
        {
            int pos;
            cin >> pos;
 
            c[i][pos + FOOD] = 1;
 
            adj[i].push_back(pos + FOOD);
            adj[pos + FOOD].push_back(i);
        }
    }
 
 
    int totalFlow = 0;
 
    while (1)
    {
        vector<int> prev(502, -1);
 
        queue<int> q;
        q.push(S);
 
        while (!q.empty() && prev[T] == -1)
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
        if (prev[T] == -1)
            break;
 
        int flow = INF;
 
        for (int i = T; i != S; i = prev[i])
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
 
        for (int i = T; i != S; i = prev[i])
        {
        //    cout << "i :: " << i << endl;
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        totalFlow += flow;
 
    }
 
    cout << totalFlow;
 
    return 0;
}