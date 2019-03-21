n,m=map(int,input().split())
r=1
for i in range(m):
    r*=n-i
    r//=i+1
print(r)