def get(L, i, j):
    if 0<=i<len(L) and 0<=j<len(L[0]): return L[i][j]
    return "#"

from sys import stdin
input = stdin.readline
from collections import deque
INF = float('inf')
for TEST in range(int(input())):
    w, h = map(int,input().split())
    L = [list(input().rstrip()) for i in range(h)]
    fire = []
    for i in range(h):
        for j in range(w):
            if L[i][j] == "@": pi, pj = i, j
            if L[i][j] == "*": fire.append((i,j))
    Q = deque()
    Q.append((pi,pj,"@"))
    for fi, fj in fire: Q.append((fi,fj,"*"))
    for TIME in range(1, 9999999999):
        if not len(Q) or Q[0][2] != "@": print("IMPOSSIBLE"); break
        for _ in range(len(Q)):
            i, j, c = Q.popleft()
            if L[i][j] != c: continue
            if c == "@" and (i in (0,h-1) or j in (0,w-1)): print(TIME); break
            for ni, nj in (i-1,j), (i+1,j), (i,j-1), (i,j+1):
                if c == "@" and L[ni][nj] == ".":
                    L[ni][nj] = "@"; Q.append((ni,nj,"@"))
                if c == "*" and get(L,ni,nj) in ".@":
                    L[ni][nj] = "*"; Q.append((ni,nj,"*"))
        else: continue
        break