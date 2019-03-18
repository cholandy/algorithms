def recolor(x, y):
    ans = 0
    for i in range(x,x+8):
        for j in range(y,y+8):
            if 'BW'[(i+j)%2] != board[j][i]:
                ans+= 1
    return min(ans, 64-ans)

a, b = map(int,input().split())
board = [input() for i in range(a)]

ans = 64
for i in range(b-7):
    for j in range(a-7):
        ans = min(ans, recolor(i,j))
print(ans)