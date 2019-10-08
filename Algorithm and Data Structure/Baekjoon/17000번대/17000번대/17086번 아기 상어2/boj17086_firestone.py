import sys;sys.stdin=open('input1.txt','r')
input=__import__('sys').stdin.readline

n,m=map(int,input().split())
sea=[]
for i in range(n):
    row=list(map(int,input().split()))
    for j in range(m):
        if row[j]==0:
            row[j]=-1
            continue
        elif row[j]==1: 
            row[j]=0
    sea.append(row)
# [print(*i) for i in sea]
cnt=1
d=((-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1))
def cool(arr):
    for i in range(n):
        for j in range(m):
            if arr[i][j]==-1:return False
    return True
while 1:
    for i in range(n):
        for j in range(m):
            if sea[i][j]==-1:continue
            if sea[i][j]==cnt-1:
                sea[i][j]=cnt
                for x,y in d:
                    ni,nj=i+x,j+y
                    if 0<=ni<n and 0<=nj<m and sea[ni][nj]==-1:
                        sea[ni][nj]=cnt
    if cool(sea):break
    else: cnt+=1
print(cnt)
