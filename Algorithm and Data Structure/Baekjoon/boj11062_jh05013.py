from sys import setrecursionlimit as SRL
SRL(12341234)
def dp(i, j):
    if opt[i][j] != -1: return opt[i][j]
    elif i == j: res = card[i] if n%2 == 1 else 0
    elif (j-i)%2 == n%2: res = min(dp(i+1, j), dp(i, j-1))
    else: res = max(card[i]+dp(i+1, j), card[j]+dp(i, j-1))
    opt[i][j] = res
    return res

for TEST in range(int(input())):
    n = int(input())
    card = list(map(int,input().split()))
    opt = [[-1]*n for i in range(n)]
    print(dp(0, n-1))
