import sys

w, h, n = map(int,sys.stdin.readline().split())
nx, ny = map(int,sys.stdin.readline().split())
move = 0

for i in range(1,n):
    dx, dy = map(int,sys.stdin.readline().split())
    if((nx-dx)*(ny-dy) > 0):
        if(nx > dx):
            move += nx-dx+ny-dy-min(nx-dx,ny-dy)
        else:
            move += dx-nx+dy-ny-min(dx-nx,dy-ny)
    else:
        move += abs(nx-dx)+abs(ny-dy)
    nx, ny = dx, dy

print(move)
