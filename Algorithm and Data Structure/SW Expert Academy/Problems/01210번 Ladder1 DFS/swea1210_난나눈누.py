import sys
sys.stdin = open('01210번 Ladder1\input.txt', 'r')

def dfs(arr, x, y):
    if x<0 or y<0 or x>99 or y>99 or arr[x][y]==0: return

    if arr[x][y]==2: return x,y
    
    arr[x][y]==0
    dfs(arr, x, y+1)
    dfs(arr, x, y-1)
    dfs(arr, x+1, y)

for tc in range(10):
    a=int(input())
    board=[list(map(int,input().split())) for i in range(100)]

    for i in range(100):
        if board[0][i]==1:
            print(dfs(board, 0, i))
    