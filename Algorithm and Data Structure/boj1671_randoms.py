N=int(input())
L=[list(map(int,input().split()))for i in range(N)]
c=[[]for i in range(N)]
for i in range(N):
    for j in range(N):
        if L[i][0]>=L[j][0] and L[i][1]>=L[j][1] and L[i][2]>=L[j][2]:
            if L[i]==L[j] and i<=j:
                continue
            c[i].append(j)
a=[0]*N
b=[-1]*N
def dfs(i):
    global a,b,c
    if a[i]:return 0
    a[i]=1
    for j in c[i]:
        if b[j]==-1 or dfs(b[j]):
            b[j]=i
            return 1
    return 0
s=0
for j in range(2):
    for i in range(N):
        a=[0]*N
        s+=dfs(i)
print(N-s)