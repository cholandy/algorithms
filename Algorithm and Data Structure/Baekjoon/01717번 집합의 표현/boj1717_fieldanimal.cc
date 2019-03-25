#include<stdio.h>
#include<string.h>
int parent[1000001];
int find(int i)
{
    if (parent[i] == i)
        return i;
    int j = find(parent[i]);
    parent[i] = j;
    return j;
}
void combine(int i, int j)
{
    parent[find(j)] = find(i);
}
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
 
    for (int i = 0; i <= N; ++i)
        parent[i] = i;
    while (M--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0)
            combine(b, c);
        else
            if (find(b) == find(c))
                printf("YES\n");
            else
                printf("NO\n");
    }
}
 