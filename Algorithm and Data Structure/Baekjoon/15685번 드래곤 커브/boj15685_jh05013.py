MIS = lambda: map(int,input().split())

dj = [1,0,-1,0]
di = [0,-1,0,1]
dragon = [None]*1048580
for d in range(21):
    x = 0
    for i in range(2**d-1, 1048580, 2**(d+1)):
        dragon[i] = x
        x = 1-x

grid = [[0]*101 for i in range(101)]
for i in range(int(input())):
    y, x, d, g = MIS()
    grid[x][y] = 1
    for mov in range(2**g):
        x+= di[d]; y+= dj[d]
        grid[x][y] = 1
        d = (d-1)%4 if dragon[mov] else (d+1)%4
count = 0
for i in range(100):
    for j in range(100):
        count+= grid[i][j] and grid[i][j+1] and grid[i+1][j] and grid[i+1][j+1]
print(count)