import sys
input=sys.stdin.readline
while True:
    n=int(input())
    if n==0:
        break
    r=1
    for i in range(n+n):
        r*=i+1
    for i in range(n):
        r//=(i+1)**2
    print(r//(n+1))