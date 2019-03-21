n, k = map(int,input().split())
MOD = 1000000007
res = 1
k = min(k, n-k)
for i in range(k):
    res = res*(n-i) % MOD
    res = res*pow(i+1, MOD-2, MOD) % MOD
print(res)