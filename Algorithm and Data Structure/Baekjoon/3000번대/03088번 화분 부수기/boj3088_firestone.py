from collections import deque
N = int(input())
arr = deque()
for _ in range(N):
    a, b, c = map(int, input().split())
    arr.append((a, b, c))

ans = 0
ret = []
for points1 in range(int(N/2)):
    key = True
    count = 0
    for points2 in arr[points1+1:]:
        if set(arr[points1], arr[points2]) != None:
            count += 1
            continue
        else:
            key = False
        ret.append((points1, count))

        if key == False:
            continue
