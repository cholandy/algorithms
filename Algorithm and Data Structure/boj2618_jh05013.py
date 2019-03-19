from sys import setrecursionlimit as SRL
SRL(23232)

def start(ty):
    return (1,1) if ty == 0 else (n,n)

def dist(i, j, ty):
    xi, yi = p[i] if i else start(ty)
    xj, yj = p[j] if j else start(ty)
    return abs(xi-xj) + abs(yi-yj)

def update(i, j):
    nx = max(i, j) + 1
    if nx == w+1: return
    D = dp[i][j]+dist(i,nx,1)
    if dp[nx][j] > D: dp[nx][j], prev[nx][j] = D, (i,j)
    D = dp[i][j]+dist(j,nx,0)
    if dp[i][nx] > D: dp[i][nx], prev[i][nx] = D, (i,j)

n = int(input())
w = int(input())
p = [(-1,-1)] + [tuple(map(int,input().split())) for i in range(w)]
dp = [[float('inf')]*(w+1) for i in range(w+1)]
prev = [[(-1,-1)]*(w+1) for i in range(w+1)]
dp[0][0] = 0
for v in range(w+1):
    # update [v+1][j]
    for i in range(v+1): update(i, v)
    for j in range(v): update(v, j)

opt = float('inf')
pos = (-1,-1)
for i in range(w+1):
    if opt > dp[i][-1]: opt, pos = dp[i][-1], (i,w)
    if opt > dp[-1][i]: opt, pos = dp[-1][i], (w,i)
print(opt)
sol = []
for i in range(w):
    nex = prev[pos[0]][pos[1]]
    if pos[0] != nex[0]: sol.append(2)
    else: sol.append(1)
    pos = nex
print(*reversed(sol), sep='\n')