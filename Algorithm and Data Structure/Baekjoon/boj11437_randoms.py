N=int(input())
G=[[]for i in range(N+1)]
for i in range(N-1):
    a,b=map(int,input().split())
    G[a].append(b)
    G[b].append(a)
D=[0 for i in range(N+1)]
P=[[0]*20 for i in range(N+1)]
D[1]=1
st=[1]
while st:
    i=st.pop()
    for j in G[i]:
        if not D[j]:
            D[j]=D[i]+1
            k=0
            t=i
            while 2**k<=D[j]:
                P[j][k]=t
                t=P[t][k]
                k+=1
            st.append(j)
M=int(input())
for _ in range(M):
    a,b=map(int,input().split())
    if D[a]>D[b]:
        k=0
        for i in bin(D[a]-D[b])[2:][::-1]:
            if i=='1':
                a=P[a][k]
            k+=1
    else:
        k=0
        for i in bin(D[b]-D[a])[2:][::-1]:
            if i=='1':
                b=P[b][k]
            k+=1
    k=19
    while a!=b:
        if P[a][k]!=P[b][k] or (not k and P[a][k]==P[b][k]):
            a,b=P[a][k],P[b][k]
        k-=1
        if k<0:k=0
    print(a)