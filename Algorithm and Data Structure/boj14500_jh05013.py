tetro = (((1,1,1,1),),
         ((1,),(1,),(1,),(1,)),
         ((1,1),(1,1)),
         ((1,0),(1,0),(1,1)),
         ((1,1,1),(1,0,0)),
         ((1,1),(0,1),(0,1)),
         ((0,0,1),(1,1,1)),
         ((0,1),(0,1),(1,1)),
         ((1,0,0),(1,1,1)),
         ((1,1),(1,0),(1,0)),
         ((1,1,1),(0,0,1)),
         ((1,0),(1,1),(0,1)),
         ((0,1,1),(1,1,0)),
         ((0,1),(1,1),(1,0)),
         ((1,1,0),(0,1,1)),
         ((1,1,1),(0,1,0)),
         ((0,1),(1,1),(0,1)),
         ((0,1,0),(1,1,1)),
         ((1,0),(1,1),(1,0)))

def place(piece, y, x):
    return sum(grid[y+i][x+j]*piece[i][j] for i in range(len(piece)) for j in range(len(piece[0])))

input = raw_input
range = xrange
n, m = map(int,input().split())
grid = [list(map(int,input().split())) for i in range(n)]
res = 0
for p in tetro:
    for y in range(n-len(p)+1):
        for x in range(m-len(p[0])+1):
            res = max(res, place(p, y, x))
print(res)