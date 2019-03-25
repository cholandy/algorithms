#include <stdio.h>
 
int n, m;
int parent[1000001];
int rank[1000001];
 
void init()
{
    int i;
    for (i = 0; i <= n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
}
 
int find(int one)
{
    if (parent[one] == one)    return one;
    return find(parent[one]);
}
 
void unionset(int one, int two)
{
    int u, v;
 
    u = find(one);
    v = find(two);
 
    if (u == v)    return;
    if (rank[u] > rank[v])         parent[v] = u;
    else if (rank[u] == rank[v]) {
        parent[v] = u;
        rank[u]++;
    }
    else     parent[u] = v;
}
 
int main()
{
    int i;
    int order, one, two;
 
    scanf("%d %d", &n, &m);
 
    init();
 
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &order, &one, &two);
 
        if (order) {
            if (find(one) == find(two))    printf("YES\n");
            else                           printf("NO\n");
        }
        else {
            unionset(one, two);
        }
    }
 
    return 0;
}
