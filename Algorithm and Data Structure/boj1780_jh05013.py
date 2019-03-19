def count(p,x,y,size):
    if size == 1:
        if p[y][x] == -1:
            return (1,0,0)
        if p[y][x] == 0:
            return (0,1,0)
        return (0,0,1)
    a,b,c = 0,0,0
    nx = size//3
    sub = [count(p,x,y,nx),
           count(p,x+nx,y,nx),
           count(p,x+2*nx,y,nx),
           count(p,x,y+nx,nx),
           count(p,x+nx,y+nx,nx),
           count(p,x+2*nx,y+nx,nx),
           count(p,x,y+2*nx,nx),
           count(p,x+nx,y+2*nx,nx),
           count(p,x+2*nx,y+2*nx,nx)]
    sub.sort()
    if sub[0]==sub[-1] and sum(sub[0]) == 1:
        return sub[0]
    return (sum(sub[i][0] for i in range(9)),
            sum(sub[i][1] for i in range(9)),
            sum(sub[i][2] for i in range(9)))

n = int(input())
paper = [list(map(int,input().split())) for i in range(n)]
for i in count(paper,0,0,n):
    print(i)