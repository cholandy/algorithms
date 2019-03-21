def interfere(l, r):
    amin, amax = A[0], A[-1]
    bmin, bmax = B[l], B[~r]
    return max(amin*bmin, amin*bmax, amax*bmin, amax*bmax)

MIS = lambda: map(int,input().split())
n, k = MIS()
A = sorted(MIS())
B = sorted(MIS())
res = 78787**2
for l in range(k+1):
    res = min(res, interfere(l, k-l))
print(res)