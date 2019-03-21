def f(a,b):
    M,k=2*max(abs(a),abs(b)),2*(a>b)-1
    return M*M+1-(M+a+b)*k
a,b,c,d=map(int,input().split())
M,k,m=[[]for i in "a"*(c-a+1)],0,0
for j in range(a,c+1):
    for i in range(b,d+1):
        x=str(f(i,j))
        M[k].append(x)
        m=max(m,len(x))
    k+=1
for i in range(len(M)):
    for j in range(d-b+1):
        print(('{0:>'+str(m)+'}').format(M[i][j]),end=" ")
    print()