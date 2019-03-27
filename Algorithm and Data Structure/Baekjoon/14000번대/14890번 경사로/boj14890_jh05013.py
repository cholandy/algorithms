def usable(L):
    placed = [0]*n
    for i in range(1, n):
        if abs(L[i-1] - L[i]) >= 2: return False
        if L[i-1] > L[i]:
            for j in range(i, i+l):
                if j >= n or placed[j]: return False
                placed[j] = -1
        elif L[i-1] < L[i]:
            for j in range(i-1, i-l-1, -1):
                if j < 0 or placed[j]: return False
                placed[j] = 1
    return True

n, l = map(int,input().split())
grid = [list(map(int,input().split())) for i in range(n)]
poss = 0
for row in grid: poss+= usable(row)
for i in range(n): poss+= usable([grid[j][i] for j in range(n)])
print(poss)