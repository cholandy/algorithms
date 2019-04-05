import sys;sys.stdin=open('input1.txt','r')
from itertools import combinations as cb

def check(arr):
    for j in range(W):
        next = 0
        cnt = 1
        for i in range(D-1):
            if D-i<K and cnt==1:break
            if arr[i][j] == arr[i+1][j]:cnt += 1
            else:cnt = 1
            if cnt == K:next=1;break
        if not next:
            return False
    return True


def solve(depth):
    global ans, temp
    if depth == D:
        ans = min(ans,D)
        return
    comb = cb(idx, depth)
    temp = film[:]
    for c in comb:
        for j in range(2):
            for i in c:
                temp[i] = pattern[j]
            if check(temp):
                ans = min(ans, depth)
                return
            temp = film[:]

for t in range(int(input())):
    D,W,K=map(int, input().split())
    film=[list(map(int, input().split())) for _ in range(D)]
    pattern=[[0]*W, [1]*W]
    idx = list(range(D))
    visited = [0] * D
    ans = float('inf')
    if check(film) or K <= 1:
        ans = 0
    else:
        for i in range(1, D + 1):
            if i >= ans:
                break
            solve(i)
    print('#{} {}'.format(t+1, ans))