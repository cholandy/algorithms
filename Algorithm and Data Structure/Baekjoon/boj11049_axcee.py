import sys; input = lambda: sys.stdin.readline().rstrip()
from math import inf

def solve(n, rc) :
    v = [[0 if i==j else inf for i in range(n)] for j in range(n)]
    for d in range(1, n) :
        for i in range(n-d) :
            j = i+d
            for k in range(i, j) :
                v[i][j] = min(v[i][j], v[i][k] + v[k+1][j] + rc[i]*rc[k+1]*rc[j+1])
    return v[0][n-1]

n = int(input())
rc = [int(input().split()[0]) for i in range(n-1)]
rc.extend(map(int,input().split()))
print(solve(n, rc))
