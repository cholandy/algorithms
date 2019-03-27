import sys
input=sys.stdin.readline
n=int(input())
s=input().split()
def f(x,y):
    if x>n:
        return 1
    global s
    for i in range(10):
        if v[9-i]:
            continue
        if x==0 or s[x-1]=='<' and y<9-i or s[x-1]=='>' and y>9-i:
            v[9-i]=1
            t=f(x+1,9-i)
            if t:
                global r
                r+=str(9-i)
                return 1
            v[9-i]=0
    return 0
def g(x,y):
    if x>n:
        return 1
    global s
    for i in range(10):
        if v[i]:
            continue
        if x==0 or s[x-1]=='<' and y<i or s[x-1]=='>' and y>i:
            v[i]=1
            t=g(x+1,i)
            if t:
                global r
                r+=str(i)
                return 1
            v[i]=0
    return 0
v=[0]*10
r=""
f(0,0)
print(r[::-1])
v=[0]*10
r=""
g(0,0)
print(r[::-1])