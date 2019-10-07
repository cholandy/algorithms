from collections import deque

def get(L, i, j):
    if 0<=i<len(L) and 0<=j<len(L[0]): return L[i][j]
    return "X"

def bfs():
    for TIME in range(len(Q)):
        i, j, c = Q.popleft()
        if grid[i][j] != c: continue
        for ni, nj in (i-1,j), (i+1,j), (i,j-1), (i,j+1):
            a, b = grid[i][j], get(grid, ni, nj)
            if a+b in ("S.", "*.", "*S"):
                grid[ni][nj] = a
                Q.append((ni,nj,a))
            elif a+b == "SD":
                return True
    return False

r, c = map(int,input().split())
Q = deque()
grid = []
water = []
for i in range(r):
    row = input()
    for j in range(c):
        if row[j] == "*": water.append((i,j))
        elif row[j] == "S": Q.append((i,j,"S"))
    grid.append(list(row))
for i, j in water: Q.append((i,j,"*"))

for i in range(r*c):
    if bfs():
        print(i+1)
        break
else: print("KAKTUS")
