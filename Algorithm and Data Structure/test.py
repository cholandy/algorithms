import sys;sys.stdin=open('input2.txt','r')

def getpoint():
    for x in range(10):
        for y in range(10):
            if grid[x][y]==1:
                return (x,y)
    return -1,-1

def stick(nums, cnt):
    global ans,grid,papers
    if ans<=cnt:return
    if nums==0:ans=min(cnt,ans)
    x,y = getpoint()
    if (x,y)==(-1,-1) :return
    for i in range(4,-1,-1):
        if papers[i]:
            fx,fy,points,flag= x+i,y+i,[],1
            for nx in range(x, fx):
                for ny in range(y, fy):
                    if -1<nx<10 and -1<ny<10:
                        if grid[nx][ny]:
                            points.append((nx,ny))
                            grid[nx][ny]=0
                        else:
                            flag=0;break
                if flag==0:break
            if flag:
                papers[i]-=1
                nums-=(i+1)**2
                stick(nums, cnt+1)
                nums+=(i+1)**2
                papers[i]+=1
            for a,b in points:
                grid[a][b] = 1
for tc in range(int(input())):
    grid = [list(map(int, input().split())) for _ in range(10)]
    papers = [5]*5
    nums = len([True for i in range(10) for j in range(10) if grid[i][j]==1])
    ans = float('inf')
    stick(nums, 0)
    print(f'#{tc+1} {ans}')