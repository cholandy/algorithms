import sys
sys.stdin = open('01210번 Ladder1 DFS\input.txt', 'r')

def dfs(x,y):
    if x==0:return y
    # visit[x][y]=True
    arr[x][y]=0
    if y-1>=0 and arr[x][y-1]:
        return dfs(x,y-1)
    elif y+1<100 and arr[x][y+1]:
        return dfs(x,y+1)
    else:
        return dfs(x-1,y)

for tc in range(10):
    case = int(input())

    arr = [list(map(int,input().split())) for _ in range(100)]
    sx=sy=0
    for i in range(100):
        if arr[99][i]==2:
            sx,sy=99,i
            break
    # visit=[[False]*100 for _ in range(100)]        
    ans=0
    print(f'#{tc+1}', dfs(sx,sy))