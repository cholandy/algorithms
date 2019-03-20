import sys
input=sys.stdin.readline
u,v=input().split()
s=list(u)
for i in range(int(v)-3):
    t=['0']
    for j in range(len(s)):
        for k in range(j):
            s[j],s[k]=s[k],s[j]
            if s>t:
                t=s[:]
            s[j],s[k]=s[k],s[j]
    if t[0]=='0':
        print(-1)
        sys.exit()
    s=t
def f(a,n):
    if not n or a[0]=='0':
        return a
    r=['0']
    for i in range(len(a)):
        for j in range(i):
            a[i],a[j]=a[j],a[i]
            t=f(a[:],n-1)
            a[i],a[j]=a[j],a[i]
            if t>r:
                r=t
    return r
s=f(s,min(int(v),3))
if s[0]=='0':
    print(-1)
    sys.exit()
print(''.join(s))