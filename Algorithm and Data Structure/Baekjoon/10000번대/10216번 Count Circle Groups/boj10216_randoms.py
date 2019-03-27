T=int(input())
for _ in range(T):
    N=int(input())
    E=[tuple(map(int,input().split()))for i in range(N)]
    G=[[]for i in range(N)]
    for i in range(N):
        x1,y1,r1=E[i]
        for j in range(i+1,N):
            x2,y2,r2=E[j]
            if (x1-x2)**2+(y1-y2)**2<=(r1+r2)**2:
                G[i].append(j)
                G[j].append(i)
    M=[-1for i in range(N)]
    c=0
    st=[]
    for i in range(N):
        if M[i]==-1:
            c+=1
            st.append(i)
        while st:
            p=st.pop()
            if M[p]==-1:
                M[p]=c
                for j in G[p]:
                    if M[j]==-1:
                        st.append(j)
    print(c)