from itertools import combinations
def convert(s):
    s = int(s)
    if s == 0:
        return float('inf')
    return s

n = int(input())
w = [list(map(convert,input().split())) for i in range(n)]
C = {}

def TSP(n, w):
    #C = {}
    for k in range(1, n):
        C[(1+(1<<k),k)] = w[0][k]
    for s in range(2, n+1):
        for S in combinations(range(1,n), s):
            val = sum(1<<k for k in S)+1
            for k in S:
                C[(val,k)] = min(C[(val-(1<<k),m)]+w[m][k] for m in S if m!=0 and m!=k)
    return min(C[((2<<n-1)-1,k)] + w[k][0] for k in range(1,n))

print(TSP(n,w))