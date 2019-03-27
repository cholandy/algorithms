N,M=map(int,input().split())
c=[[]for i in range(N)]
for i in range(N):
    _,*L=map(int,input().split())
    for j in L:
        c[i].append(j)
tf=0
a=[0]*N
b=[-1]*(M+1)
def dfs(i):
    global a,b,c
    if a[i]:return 0
    a[i]=1
    for j in c[i]:
        if b[j]==-1 or dfs(b[j]):
            b[j]=i
            return 1
    return 0
for i in range(N):
    for j in range(2):
        a=[0]*N
        tf+=dfs(i)
print(tf)