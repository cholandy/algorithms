N=int(input())
M=[[0]*(N+2)]+[[0]+list(map(int,input().split()))+[0]for i in range(N)]+[[0]*(N+2)]
def f(h):
    global N,M
    V=[[0]*(N+2)for i in range(N+2)]
    c=0
    for i in range(1,N+1):
        for j in range(1,N+1):
            if M[i][j]>h and not V[i][j]:
                V[i][j]=1
                c+=1
                q=[(i,j)]
                while q:
                    x,y=q.pop()
                    for a,b in [(0,1),(0,-1),(1,0),(-1,0)]:
                        if M[x+a][y+b]>h and not V[x+a][y+b]:
                            q.append((x+a,y+b))
                            V[x+a][y+b]=1
    return c
print(max(map(f,range(101))))