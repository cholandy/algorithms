import sys;sys.stdin=open('input.txt','r')

mat = [list(map(int, input().split())) for _ in range(10)]
papers=[0,5,5,5,5,5]

points_cnt=len([1 for i in range(10) for j in range(10) if mat[i][j]])
ans = 100

def dfs(point_cnt, cnt, grid):
    global ans
    if point_cnt==0:
        ans=min(cnt, ans)
        return
    if cnt>=ans:return
    x,y=-1,-1
    for i in range(10):
        for j in range(10):
            if grid[i][j]==1:
                x,y=i,j
                break
        if y!=-1:break
    if x==-1:return
    for i in range(5,0,-1):
        if papers[i]==0:continue
        else:
            flag = 1
            change=[]
            fx,fy = x+i, y+i
            if fx>10 or fy>10: continue
            for a in range(x,fx):
                for b in range(y,fy):
                    if grid[a][b]==0:
                        flag=0
                        break
                    else:
                        change.append((a,b))
                if flag==0:
                    change.clear()
                    break
            if flag:
                for o,p in change:
                    grid[o][p]=0
                cnt+=1
                papers[i] -= 1
                point_cnt-=i**2
                dfs(point_cnt, cnt, grid)
                point_cnt+=i**2
                papers[i]+=1
                cnt-=1
                for o,p in change:
                    grid[o][p]=1

dfs(points_cnt, 0, mat)
print(ans if ans!=100 else -1)




