from collections import deque
N = int(input())
arr = deque()
for _ in range(N):
    a, b, c = map(int, input().split())
    arr.append((a, b, c))

ans = 0
