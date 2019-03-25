n = int(input())
grid = [list(map(int,input().split())) for i in range(n)]

from collections import deque
def LR(L, d):
    # -1 R, 1 L
    new = []
    Q = deque()
    for row in L:
        for i in filter(None, row[::d]): Q.append(i)
        newrow = []
        while Q:
            i = Q.popleft()
            if Q and i == Q[0]: Q.popleft(); newrow.append(i*2)
            else: newrow.append(i)
        newrow+= [0]*(n-len(newrow))
        new.append(newrow[::d])
    return new

def UD(L, d):
    # -1 D, 1 U
    new = LR(list(zip(*L)), d)
    return list(zip(*new))

def dfs(L, move):
    res = max(map(max, L))
    if move == 0: return res
    for d in -1, 1:
        res = max(res, dfs(LR(L, d), move-1))
        res = max(res, dfs(UD(L, d), move-1))
    return res

print(dfs(grid, 10))