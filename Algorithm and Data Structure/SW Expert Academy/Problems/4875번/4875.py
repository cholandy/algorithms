import sys
sys.stdin = open('input.txt','r')

def DFSr(x, y):
    global found

    if not 0 <= x < N or not 0 <= y < N or found or maze[x][y] == 1 :
        return
    if maze[x][y] == 3 :
        found = 1
        return

    maze[x][y] = 1
    DFSr(x, y+1)
    DFSr(x, y-1)
    DFSr(x+1, y)
    DFSr(x-1, y)


T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    maze = [[int(x) for x in input()] for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if maze[i][j] == 2 :
                X = i
                Y = j

    found = 0
    DFSr(X, Y)
    print('#%d'%tc, found)
