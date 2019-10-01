N = int(input())
arr = [[0, 0, 0] for _ in range(N)]
check = [False] * 1001001  # 처음에는 안 깨졌다.
ans, val = 0, 0

for i in range(N):
    points = list(map(int, input().split()))
    flag = True
    for j in range(3):
        arr[i][j] = points[j]
        val = arr[i][j]
        if check[val]:
            flag = False
        else:
            check[val] = True
    if flag:
        ans += 1
print(ans)
