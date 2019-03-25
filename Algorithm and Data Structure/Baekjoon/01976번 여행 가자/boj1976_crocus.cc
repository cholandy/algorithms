#include <iostream>
#include <cstdio>
 
#define swap(a,b){int t = a; a = b; b = t;}
 
using namespace std;
 
// parent[a] = b :: a의 부모는 b다
int parent[201];
int level[201];
 
int find(int u)
{
    // 루트 노드이면 return u
    if (u == parent[u])
        return u;
 
    // 그 외에는 자신의 루트를 찾으러 간다.
    return parent[u] = find(parent[u]);
}
 
void merge(int u, int v)
{
    u = find(u);
    v = find(v);
 
    // 루트가 같다면 이미 같은 트리
    if (u == v)
        return;
 
    // u가 v보다 더 깊은 트리라면 swap
    if (level[u] > level[v])
        swap(u, v); // 항상 u가 더 작은 트리가 되도록 한다. 
 
    // u의 루트가 v가 되도록
    parent[u] = v;
 
    // u와 v의 깊이가 같을 때 v의 깊이를 늘려준다.
    if (level[u] == level[v]) 
        ++level[v];
}
 
int main()
{
    int n, m;
 
    scanf("%d %d", &n, &m);
 
    // 초기에는 자신의 부모는 자기 자신
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        level[i] = 1;
    }
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int val;
            scanf("%d", &val);
 
            if (j > i && val == 1)
                merge(i, j);
        }
    }
 
    bool chk = true;
    int val;
    scanf("%d", &val);
 
    int u = find(val);
    for (int i = 0; i < m - 1; i++)
    {
        scanf("%d", &val);
 
        if (u != find(val))
        {
            chk = false;
            break;
        }    
    }
 
    chk ? printf("YES") : printf("NO");
 
    return 0;
}
