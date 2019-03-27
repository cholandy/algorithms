n, m = map(int,input().split())
if m: unavail = set(map(int,input().split()))
else: unavail = set()
opt = [[float('inf')]*200 for i in range(n+6)]
# [i][j] = play i days, j coupons remaining
opt[0][0] = 0

for i in range(n):
    for j in range(50):
        if opt[i][j] == float('inf'): continue
        if i+1 in unavail:
            opt[i+1][j] = min(opt[i+1][j], opt[i][j])
            continue
        opt[i+1][j] = min(opt[i+1][j], opt[i][j]+10)
        for k in 1,2,3:
            opt[i+k][j+1] = min(opt[i+k][j+1], opt[i][j]+25)
        for k in 1,2,3,4,5:
            opt[i+k][j+2] = min(opt[i+k][j+2], opt[i][j]+37)
        if j >= 3:
            opt[i+1][j-3] = min(opt[i+1][j-3], opt[i][j])
print(min(opt[n]) * 1000)
