n,m=map(int,input().split())
a=[input() for i in range(n)]
r=66
for i in range(n-7):
    for j in range(m-7):
        t=0
        for k in range(8):
            for l in range(8):
                if k%2==l%2 and a[i+k][j+l]=='B':
                    t+=1
                if k%2!=l%2 and a[i+k][j+l]=='W':
                    t+=1
        r=min(r,t)
        t=0
        for k in range(8):
            for l in range(8):
                if k%2!=l%2 and a[i+k][j+l]=='B':
                    t+=1
                if k%2==l%2 and a[i+k][j+l]=='W':
                    t+=1
        r=min(r,t)
print(r)