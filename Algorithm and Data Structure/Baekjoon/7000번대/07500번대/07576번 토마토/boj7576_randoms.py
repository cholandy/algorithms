w,h=map(int,input().split())
M=[list(map(int,input().split())) for _ in range(h)]
T=[[-1]*w for _ in range(h)]
st=[[],[]]
c=0
for i in range(h):
    for j in range(w):
        if M[i][j]==1:
            st[c%2].append((i,j))
t=False
while 1:
    if st[0]==st[1]:
        c-=1
        break
    while st[c%2]:
        a,b=st[c%2].pop()
        if a!=0:
            if M[a-1][b]==0:
                st[(c+1)%2].append((a-1,b))
                M[a-1][b]=1
        if b!=0:
            if M[a][b-1]==0:
                st[(c+1)%2].append((a,b-1))
                M[a][b-1]=1
        if a!=h-1:
            if M[a+1][b]==0:
                st[(c+1)%2].append((a+1,b))
                M[a+1][b]=1
        if b!=w-1:
            if M[a][b+1]==0:
                st[(c+1)%2].append((a,b+1))
                M[a][b+1]=1
    c+=1
for i in M:
    for j in i:
        if j==0:
            c=-1
print(c)