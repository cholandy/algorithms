import sys; sys.stdin=open('input.txt','r')

r,c,m = map(int, input().split())
sea = [[0 for _ in range(c)] for _ in range(r)]
if m==0: print(0);exit()

direc = [0,[-1,0],[1,0],[0,1],[0,-1]]
change = [0,2,1,4,3]

for _ in range(m):
    r,c,s,d,z = map(int, input().split())
    sea[r-1][c-1] = [s,d,z]
    

# [print(*i) for i in sea ]

def fishing(cnt):
    for i in range(r):
        if sea[r][cnt]:
            return sea[r][cnt][2]

def move():
    for i in range(r):
        for j in range(c):
            if sea[r][c]:
                go()

catch = 0
cnt = -1
while cnt<c:
    cnt+=1
    catch += fishing(cnt)
    move()

print(catch)