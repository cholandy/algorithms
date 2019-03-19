import sys
sys.setrecursionlimit(100000000)
# def input(): return sys.stdin.readline()[:-1]
def iin(): return int(input())
def impin(): return map(int, input().split())
def irrin(): return [int(x) for x in input().split()]
def imrin(n): return [int(input()) for _ in range(n)]


def f(arr, c, trr):
    if c==0:
        rrr.append(''.join(trr))
        return
    for i in range(len(arr)):
        if arr[i][1]>0:
            arr[i][1] -= 1
            trr.append(arr[i][0])
            f(arr, c-1, trr)
            trr.pop()
            arr[i][1] += 1


for _ in range(iin()):
    s = input()
    arr = {}
    for c in s:
        if c in arr:
            arr[c] += 1
        else:
            arr[c] = 1
    rrr = []
    f(sorted([list(x) for x in arr.items()]), sum(arr.values()), [])
    for r in rrr:
        print(r)
