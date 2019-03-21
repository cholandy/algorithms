from itertools import combinations
def TSP(n, w):
    if n <= 1: return 0
    C = {}
    for k in range(1, n): C[1+(1<<k),k] = w[0][k]
    for s in range(2, n+1):
        for S in combinations(range(1,n), s):
            val = sum(1<<k for k in S)+1
            for k in S: C[val,k] = min(C[val-(1<<k),m]+w[m][k] for m in S if m!=0 and m!=k)
    return min(C[(2<<n-1)-1,k] + w[k][0] for k in range(1,n))

def dist(c1, c2):
    x1, y1 = c1
    x2, y2 = c2
    return ((x1-x2)**2 + (y1-y2)**2) **.5

n = int(input())
city = [tuple(map(int,input().split())) for i in range(n)]
w = [[dist(city[i], city[j]) for j in range(n)] for i in range(n)]
print(TSP(n, w))