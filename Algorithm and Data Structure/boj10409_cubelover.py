import sys
input=sys.stdin.readline
n,m=map(int,input().split())
r=0
for x in map(int,input().split()):
    if m<x:
        break
    r+=1
    m-=x
print(r)