n,k = map(int, input().split())
L = list(map(int, input().split()))
s = sum(L[:k])
res = s

for i in range(k, len(L)):
    cur = L[i]
    s+= L[i]-L[i-k]
    res = max(res, s)
print(res)