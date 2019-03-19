from sys import stdin
input = stdin.readline

def bipartite():
    def union(x,y):
        xr = find(x)
        yr = find(y)
        if xr == yr:
            return
        if rank[xr] < rank[yr]:
            parent[xr] = yr
        elif rank[xr] > rank[yr]:
            parent[yr] = xr
        else:
            parent[yr] = xr
            rank[xr]+= 1
    
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    v,e = map(int,input().split())
    rank = [0]*(2*v+1)
    parent = list(range(2*v+1))
    
    for i in range(e):
        a, b = map(int,input().split())
        union(a, -b)
        union(-a, b)
    for i in range(1,v+1):
        if find(i) == find(-i):
            return "NO"
    return "YES"

for T in range(int(input())):
    print(bipartite())