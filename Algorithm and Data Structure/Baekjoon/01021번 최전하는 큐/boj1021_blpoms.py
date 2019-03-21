n, m = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0
for i in range(m):
    if arr[i]-1 < n+1-arr[i]:
        t = arr[i]-1
        for j in range(i+1, m):
            arr[j] = (arr[j]-t-1) % n
    else:
        t = n+1-arr[i]
        for j in range(i+1, m):
            arr[j] = (arr[j]+t-1) % n
    ans += t
    n -= 1
print(ans)