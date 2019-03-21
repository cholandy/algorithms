__import__('sys').setrecursionlimit(923123)
n = int(input())
grid = [list(map(int,input().split())) for i in range(n)]
dp = [[[None]*n for i in range(n)] for j in range(3)]


def get(i, j):
    if 0 <= i < n and 0 <= j < n:
         return grid[i][j]
    return 1

def gdp(i, j, state):
    if state == 0 and i == n-1 and j == n-2:
        return 1
    if state == 1 and i == n-2 and j == n-1: 
        return 1
    if state == 2 and i == n-2 and j == n-2: 
        return 1
    if dp[state][i][j] != None: 
        return dp[state][i][j]
    ans = 0
    if state == 0:
        if get(i, j+2) == 0: 
            ans+= gdp(i, j+1, 0)
        if get(i, j+2) == get(i+1, j+1) == get(i+1, j+2) == 0:
            ans+= gdp(i, j+1, 2)
    elif state == 1:
        if get(i+2, j) == 0: 
            ans+= gdp(i+1, j, 1)
        if get(i+2, j) == get(i+1, j+1) == get(i+2, j+1) == 0:
            ans+= gdp(i+1, j, 2)
    else:
        if get(i+1, j+2) == 0: 
            ans+= gdp(i+1, j+1, 0)
        if get(i+2, j+1) == 0: 
            ans+= gdp(i+1, j+1, 1)
        if get(i+1, j+2) == get(i+2, j+1) == get(i+2, j+2) == 0:
            ans+= gdp(i+1, j+1, 2)
    dp[state][i][j] = ans
    return ans

print(gdp(0, 0, 0))