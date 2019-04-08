import copy
import sys;sys.stdin=open('input1.txt','r')
from time import time

a=time()

def moving(ls, nsn):
    _ls = [[0] * M] + ls[:N-1]
    nsn -= ls[N-1].count(1)
    return [_ls, nsn]


def positioning(idx, s):
    global subset, maxcnt
    if idx == 3:
        cnt = 0
        ls = copy.deepcopy(maps)
        nsn = 0
        for i in range(N):
            for j in range(M):
                if maps[i][j]:
                    nsn += 1
        while nsn:
            shooted = []
            for i in subset:
                for j in shoot:
                    dy = j[0]
                    dx = j[1]
                    if 0 <= N - dy < N and 0 <= i + dx < M:
                        if ls[N-dy][i+dx]:
                            shooted.append((N-dy, i+dx))
                            break
            for i in shooted:
                if ls[i[0]][i[1]]:
                    ls[i[0]][i[1]] = 0
                    nsn -= 1
                    cnt += 1
            ls, nsn = moving(ls, nsn)
        if cnt > maxcnt:
            maxcnt = cnt
        return
    for i in range(s+1, M):
        subset.append(i)
        positioning(idx+1, i)
        subset.pop()

for tc in range(int(input())):
    N, M, D = map(int, input().split())
    maps = [list(map(int, input().split())) for _ in range(N)]
    maxcnt = 0
    subset = []
    shoot = []
    for i in range(1, D+1):
        for x in range(0-D, D+1):
            for y in range(1, D+1):
                if y + abs(x) == i:
                    shoot.append((y, x))
    positioning(0, -1)
    print("#{} {}".format(tc+1,maxcnt))


b=time()
print(b-a)