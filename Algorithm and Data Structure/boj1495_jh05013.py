n, s, m = map(int,input().split())
v = list(map(int,input().split()))
tunable = [[False]*(m+1) for i in range(n)] # song i can be played in volume j

for k in s+v[0], s-v[0]:
    if 0 <= k <= m: tunable[0][k] = True
for i in range(1, n):
    for j in range(m+1):
        if not tunable[i-1][j]: continue
        for k in j-v[i], j+v[i]:
            if 0 <= k <= m: tunable[i][k] = True
avail = [-1] + [j for j in range(m+1) if tunable[-1][j]]
print(max(avail))