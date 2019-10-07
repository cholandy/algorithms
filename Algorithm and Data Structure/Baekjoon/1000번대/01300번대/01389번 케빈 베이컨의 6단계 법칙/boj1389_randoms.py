n,m=map(int,input().split())
M=[[100if i!=j else 0for i in range(n+1)]for j in range(n+1)]
v=[[-1if i!=j else 0for i in range(n+1)]for j in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    M[a][b]=1
    M[b][a]=1
for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if i!=j!=k!=i:
                if M[i][k]+M[k][j]<M[i][j]:
                    M[i][j]=M[i][k]+M[k][j]
                    if v[k][j]==-1:
                        v[i][j]=k
                    else:
                        v[i][j]=v[k][j]
for i in range(1,n+1):
    for j in range(1,n+1):
        if M[i][j]==10**9:
            M[i][j]=0
def path(i,j):
    global M,v
    if M[i][j]==0:
        return 0
    else:
        L=[j]
        while v[i][L[-1]]!=-1:
            L.append(v[i][L[-1]])
        return len(L)
P=[sum([path(i,j)for j in range(1,n+1)])for i in range(1,n+1)]
print(P.index(min(P))+1)