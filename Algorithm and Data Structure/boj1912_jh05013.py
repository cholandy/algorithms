input()
L = list(map(int,input().split()))
best = L[0]
cur = 0

for i in L:
    cur+= i
    best = max(best, cur)
    if cur < 0:
        cur = 0
print(best)