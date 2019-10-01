N = int(input())
check = [0] * 1001001
ans = 0
for i in range(N):
    points = list(map(int, input().split()))
    flag = 1
    for j in range(3):
        if check[points[j]]:
            flag = 0
        else:
            check[points[j]] = 1
    if flag:
        ans += 1
print(ans)
