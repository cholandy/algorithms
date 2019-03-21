import collections


def bfs():
    q = collections.deque([[sy, sx]])
    visit = [0] * n
    while q:
        y, x = q.popleft()
        for i, a in enumerate(arr):
            cy, cx = a
            if not visit[i]:
                if abs(cy - y) + abs(cx - x) <= 1000:
                    visit[i] = 1
                    q.append([cy, cx])
        if abs(ey - y) + abs(ex - x) <= 1000:
            return True
    return False


for t_case in range(int(input())):
    n = int(input())
    sy, sx = map(int, input().split())
    arr = []
    for _ in range(n):
        arr.append(list(map(int, input().split())))
    ey, ex = map(int, input().split())
    print("happy" if bfs() else "sad")
