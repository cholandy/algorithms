N,M = map(int,input().split())
board = [input() for i in range(N)]
maxstep = [[0]*M for i in range(N)]
S = [(0,0,0)]

while S:
    x,y,step = S.pop()
    move = int(board[y][x])
    for newx,newy in ((x+move,y),(x-move,y),(x,y+move),(x,y-move)):
        if not 0<=newx<M:
            continue
        if not 0<=newy<N:
            continue
        if board[newy][newx] == "H":
            continue
        if step+1 > maxstep[newy][newx]:
            S.append((newx,newy,step+1))
            maxstep[newy][newx] = step+1
            if step+1 > N*M:
                print(-1)
                break
    else:
        continue
    break
else:
    print(max(map(max,maxstep))+1)