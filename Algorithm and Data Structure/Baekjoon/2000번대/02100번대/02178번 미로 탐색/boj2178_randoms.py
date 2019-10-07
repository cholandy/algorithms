h,w=map(int,input().split())
M=[list(map(int,input())) for _ in range(h)]
T=[[-1]*w for _ in range(h)]
st=[[],[]]
c=0
a,b=0,0
st[c%2].append((a,b))
while not(a==h-1 and b==w-1):
    while st[c%2]:
        a,b=st[c%2].pop()
        if a==h-1 and b==w-1:
            break
        if a!=0:
            if M[a-1][b]==1 and T[a-1][b]==-1:
                st[(c+1)%2].append((a-1,b))
                T[a-1][b]=0
        if b!=0:
            if M[a][b-1]==1 and T[a][b-1]==-1:
                st[(c+1)%2].append((a,b-1))
                T[a][b-1]=0
        if a!=h-1:
            if M[a+1][b]==1 and T[a+1][b]==-1:
                st[(c+1)%2].append((a+1,b))
                T[a+1][b]=0
        if b!=w-1:
            if M[a][b+1]==1 and T[a][b+1]==-1:
                st[(c+1)%2].append((a,b+1))
                T[a][b+1]=0
    c+=1
print(c)