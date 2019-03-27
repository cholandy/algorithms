import sys
input=sys.stdin.readline
n=int(input())
a=[1]*n
d=[]
for i in range(2,n):
    if a[i]:
        d.append(i)
        j=i+i
        while j<n:
            a[j]=0
            j+=i
d.reverse()
for w in d:
    for x in d:
        if w+x>n:
            continue
        for y in d:
            if w+x+y>n:
                continue
            for z in d:
                if w+x+y+z==n:
                    print(w,x,y,z)
                    exit()
print(-1)