import sys
sys.setrecursionlimit(100000000)
# def input(): return sys.stdin.readline()[:-1]
def iin(): return int(input())
def impin(): return map(int, input().split())
def irrin(): return [int(x) for x in input().split()]
def imrin(n): return [int(input()) for _ in range(n)]


def dfs(i, vrr):
    vrr[i] = True
    for j in err[i]:
        if brr[j] is None or (not vrr[brr[j]] and dfs(brr[j], vrr)):
            arr[i] = j
            brr[j] = i
            return True
    return False


n, m = impin()
err = [[] for _ in range(n)]
for i in range(n):
    for j in irrin()[1:]:
        err[i].append(j-1)
arr = [None]*n
brr = [None]*m
cnt = 0
for i in range(n):
    if arr[i] is None:
        vrr = [False]*n
        if dfs(i, vrr):
            cnt += 1
print(cnt)
