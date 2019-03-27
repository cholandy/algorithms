import sys
input=sys.stdin.readline
n=int(input())
while n!=0:
    t=0
    for i in range(n):
        s=input().strip()
        while t<len(s) and s[t]!=' ':
            t+=1
    print(t+1)
    n=int(input())