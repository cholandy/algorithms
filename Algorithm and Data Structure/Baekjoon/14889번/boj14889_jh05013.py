from itertools import combinations

n = int(input())
S = [list(map(int,input().split())) for i in range(n)]
res = float('inf')
for C in combinations(range(n), n//2):
    rest = set(range(n)) - set(C)
    cur = 0
    for i in C:
        for j in C: cur+= S[i][j]
    for i in rest:
        for j in rest: cur-= S[i][j]
    res = min(res, abs(cur))
print(res)