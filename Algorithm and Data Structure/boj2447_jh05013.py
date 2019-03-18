n = int(input())
grid = [[' ']*n for i in range(n)]

def fill(x, y, size):
    if size == 1:
        grid[y][x] = '*'
        return
    ns = size//3
    fill(x,y,ns)
    fill(x+ns,y,ns)
    fill(x+2*ns,y,ns)
    fill(x,y+ns,ns)
    fill(x+2*ns,y+ns,ns)
    fill(x,y+2*ns,ns)
    fill(x+ns,y+2*ns,ns)
    fill(x+2*ns,y+2*ns,ns)
fill(0,0,n)

for line in grid:
    print(''.join(line))