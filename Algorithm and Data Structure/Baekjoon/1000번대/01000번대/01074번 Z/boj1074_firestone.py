N,r,c=map(int,input().split())
r=bin(r)[2:]
c=bin(c)[2:]
res=0
cnt=1
for i in range(len(r)-1,-1,-1):
    if r[i]=='1':
        res+=2**(2*cnt-1)
    cnt+=1
cnt=1
for i in range(len(c)-1,-1,-1):
    if c[i]=='1':
        res+=2**(2*(cnt-1))
    cnt+=1
print(res)