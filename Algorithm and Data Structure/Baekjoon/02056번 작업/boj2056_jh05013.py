n = int(input())
t = [-1]
pre = [[]]
for i in range(n):
    tx, cond, *preb = map(int,input().split())
    t.append(tx)
    pre.append(preb)

opt = [-1]*(n+1)
for i in range(1, n+1):
    if not pre[i]: opt[i] = t[i]
    else: opt[i] = max(opt[j] for j in pre[i]) + t[i]
print(max(opt))