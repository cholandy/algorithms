import sys
input=sys.stdin.readline
n=int(input())
a=[]
for i in range(n):
    x,y=input().split()
    a.append((int(x),i,y))
a.sort()
for i in range(n):
    print(a[i][0],a[i][2])