n = int(input())
m = int(input())
g = [list() for _ in range(n)]
v = [0 for _ in range(n)]
for _ in range(m):
    i, j=map(int, input().split())
    g[i - 1].append(j - 1)
    g[j - 1].append(i - 1)
def dfs(x):
    if not v[x]:
        v[x] = 1
        for i in g[x]:
            dfs(i)
dfs(0)
print(sum(v) - 1)