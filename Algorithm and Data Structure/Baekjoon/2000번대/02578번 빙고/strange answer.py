import sys
sys.stdin = open("input.txt", "r")

m=[]
d={}
a=[]
c=0
f=0
for i in range(5):
    r=input().split()
    m+=[r]
    for j in range(5):
        d[r[j]]=(i,j)
for i in range(5):
    a+=input().split()
for i in a:
    f+=1
    y,x=d[i]
    m[y][x]=0
    c+=all([m[i][x]==0 for i in range(5)])+all([m[y][i]==0 for i in range(5)])
    if x==y:
        c+=all(m[i][i]==0 for i in range(5))
    if x+y==4:
        c+=all(m[i][4-i]==0 for i in range(5))
    if c>2:
        break
print(f)