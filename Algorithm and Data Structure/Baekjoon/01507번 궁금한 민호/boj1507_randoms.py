N=int(input())
M=[list(map(int,input().split()))for i in range(N)]
a=1
for k in range(N):
    for i in range(N):
        for j in range(N):
            if i!=j!=k!=i:
                if M[i][k]+M[k][j]<M[i][j]:
                    a=0
if a:
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if i!=j!=k!=i:
                    if M[i][k] and M[k][j] and M[i][j] and M[i][k]+M[k][j]==M[i][j]:
                        M[i][j]=0
print((a-1)+a*sum([sum(M[i])for i in range(N)])//2)