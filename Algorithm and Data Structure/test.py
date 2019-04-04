import sys;sys.stdin=open('input1.txt','r')
import itertools
 
 
def check():
    global D, W, K
    for col in range(W):
        flag = 0
        count = 1
        for row in range(D - 1):
            if D - row < K and count == 1:
                break
            if data[row][col] == data[row + 1][col]:
                count += 1
            else:
                count = 1
            if count == K:
                flag = 1
                break
        if not flag:
            return False
    return True
 
 
def solve(depth):
    global D, W, result, data
    if depth == D:
        result = min(result, D)
        return
 
    comb = itertools.combinations(idx, depth)
    for c in comb:
        for j in range(2):
            for i in c:
                data[i] = drug[j]
            if check():
                result = min(result, depth)
                return
            data = raw[:]

for t in range(int(input())):
    D, W, K = map(int, input().split())
    raw = [list(map(int, input().split())) for _ in range(D)]
    data = raw[:]
    drug = [[0]*W, [1]*W]
    idx = list(range(D))
    visited = [0] * D
    result = float('inf')
    if check() or K <= 1:
        result = 0
    else:
        for i in range(1, D + 1):
            if i >= result:
                break
            solve(i)
    print('#{} {}'.format(t+1, result))