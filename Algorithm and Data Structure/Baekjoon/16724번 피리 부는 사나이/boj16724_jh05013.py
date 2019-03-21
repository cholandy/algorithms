from sys import stdin
input = stdin.readline
MIS = lambda: map(int,input().split())
from math import gcd

def travel(i, j, mark):
    visit[i][j] = mark
    while 1:
        if grid[i][j] == "L": j-= 1
        elif grid[i][j] == "R": j+= 1
        elif grid[i][j] == "U": i-= 1
        else: i+= 1
        if visit[i][j] == mark: return 1
        if visit[i][j]: return 0
        visit[i][j] = mark

n, m = MIS()
grid = [input() for i in range(n)]
visit = [[0]*m for i in range(n)]
ans = 0
k = 1
for i in range(n):
    for j in range(m):
        if not visit[i][j]: ans+= travel(i, j, k); k+= 1
print(ans)