from collections import deque
N = int(input())
arr = deque()
check = []


def poss(a, b):
    return set(a, b)


for _ in range(N):
    if _ == 0:
        check = map(int, input().split())
        continue
    ans = 0
    comp = []
    comp = map(int, input().split())
    if poss(check, comp) != None:
        check = comp
        continue
    else:
        arr.append(comp)
