import sys
sys.setrecursionlimit(100000000)
def input(): return sys.stdin.readline()[:-1]
def iin(): return int(input())
def impin(): return map(int, input().split())
def irrin(): return [int(x) for x in input().split()]
def imrin(n): return [int(input()) for _ in range(n)]


def dfs(x, p, d):
    depth[x] = d
    parent[0][x] = p
    for y in err[x]:
        if y!=p:
            dfs(y, x, d+1)


n = iin()
err = [[] for _ in range(n)]
for _ in range(n-1):
    a, b = impin()
    err[a-1].append(b-1)
    err[b-1].append(a-1)
parent = [[None]*n for _ in range(20)]
depth = [None]*n
dfs(0, None, 0)
for i in range(1, 20):
    for x in range(n):
        if parent[i-1][x] is not None:
            parent[i][x] = parent[i-1][parent[i-1][x]]
for _ in range(iin()):
    a, b = impin()
    a -= 1
    b -= 1
    if depth[a]>depth[b]:
        a, b = b, a
    for i, x in enumerate(bin(depth[b]-depth[a])[2:][::-1]):
        if x=='1':
            b = parent[i][b]
    if a!=b:
        for i in range(20-1, -1, -1):
            if parent[i][a]!=parent[i][b]:
                a = parent[i][a]
                b = parent[i][b]
        a = parent[0][a]
    print(a+1)
