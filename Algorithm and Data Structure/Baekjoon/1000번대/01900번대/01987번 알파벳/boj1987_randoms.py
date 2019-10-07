R,C=map(int,input().split())
M=[list(map(lambda x: ord(x)-65,input())) for i in range(R)]
v=[0]*26
m=1
def b(i,j,c):
    global M,v,m
    m=max(m,c)
    for p,q in [(-1,0),(1,0),(0,-1),(0,1)]:
        if 0<=i+p<R and 0<=j+q<C and not v[M[i+p][j+q]]:
            v[M[i+p][j+q]]=1
            b(i+p,j+q,c+1)
            v[M[i+p][j+q]]=0
v[M[0][0]]=1
b(0,0,1)
print(m)