from collections import deque

def get(L, i, j):
    if 0<=i<len(L) and 0<=j<len(L[0]): return L[i][j]
    return 1

d = [(0,1), (1,0), (0,-1), (-1,0)]
direc = 0 # direction index
Q = deque() # snake
Q.append((0,0))

n = int(input())
grid = [[0]*n for i in range(n)]
grid[0][0] = 1
# 0 blank 1 snake 2 apple

apple = int(input())
for i in range(apple):
    ai, aj = map(int,input().split())
    grid[ai-1][aj-1] = 2
l = int(input())
turn = [0]*11000
for i in range(l):
    t, c = input().split()
    c = -1 if c == "L" else 1
    turn[int(t)] = c

for TIME in range(11000):
    direc = (direc+turn[TIME])%4
    i, j = Q[-1]
    di, dj = d[direc]
    if get(grid, i+di, j+dj) == 1:
        print(TIME+1)
        break
    if get(grid, i+di, j+dj) == 2:
        Q.append((i+di, j+dj))
        grid[i+di][j+dj] = 1    
        continue
    Q.append((i+di, j+dj))
    grid[i+di][j+dj] = 1
    tai, taj = Q.popleft()
    grid[tai][taj] = 0