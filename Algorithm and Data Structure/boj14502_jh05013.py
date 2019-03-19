n, m = map(int,input().split())
L = [list(map(int,input().split())) for i in range(n)]

def infect(L, y, x):
    if not 0<=y<n or not 0<=x<m:
        return
    if L[y][x]:
        return
    L[y][x] = 2
    L[-1]-= 1
    infect(L, y-1, x)
    infect(L, y+1, x)
    infect(L, y, x-1)
    infect(L, y, x+1)

def guard(L, i, j, k):
    newL = [row[:] for row in L]+[E-3]
    newL[empty[i][0]][empty[i][1]] = 1
    newL[empty[j][0]][empty[j][1]] = 1
    newL[empty[k][0]][empty[k][1]] = 1
    for y, x in virus:
        newL[y][x] = 0
        newL[-1]+= 1
        infect(newL, y, x)
    return newL[-1]#sum(newL[y][x]==0 for y in range(n) for x in range(m))

empty = [(y,x) for y in range(n) for x in range(m) if L[y][x] == 0]
virus = [(y,x) for y in range(n) for x in range(m) if L[y][x] == 2]
E = len(empty)
print(max(guard(L,i,j,k) for i in range(E-2) for j in range(i+1,E-1) for k in range(i+2,E)))