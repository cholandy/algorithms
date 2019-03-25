#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> adj[32001];
queue<int> q;
int indegree[32001];
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    while (M--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        ++indegree[b];
    }
    for (int i = 1; i <= N; ++i)
        if (indegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int c = q.front();
        printf("%d ", c);
        q.pop();
        for (int i : adj[c])
        {
            --indegree[i];
            if (indegree[i] == 0)
                q.push(i);
        }
    }
}