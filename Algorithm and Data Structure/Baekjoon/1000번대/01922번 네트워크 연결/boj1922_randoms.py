n=int(input())
m=int(input())
M=[list(map(int,input().split()))for _ in range(m)]
S=list(range(n+1))
M.sort(key=lambda x:x[2])
def find_root(i):
    global S
    while S[i]!=i:
        i,S[i]=S[i],S[S[i]]
    return i
c=wsum=0
for a,b,w in M:
    a=find_root(a)
    b=find_root(b)
    if a!=b:
        S[max(a,b)]=min(a,b)
        c+=1
        wsum+=w
    if c==n-1:
        break
print(wsum)