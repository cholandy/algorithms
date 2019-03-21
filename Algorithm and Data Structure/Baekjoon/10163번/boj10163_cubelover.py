import sys
input = sys.stdin.readline

u=[[-1]*202 for _ in range(202)]
n=int(input())
for t in range(n):
    a,b,c,d=map(int,input().split())
    for i in range(a, a + c):
        for j in range(b, b + d):
            u[i][j]=t
r=[0]*(n+1)
for i in u:
    for j in i:
        r[j]+=1
for t in range(n):
    print(r[t])