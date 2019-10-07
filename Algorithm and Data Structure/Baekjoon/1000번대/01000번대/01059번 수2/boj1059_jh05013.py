from bisect import bisect
L = int(input())
luck = [0]+list(map(int,input().split()))
luck.sort()
n = int(input())

if n in luck:
    print(0)
else:
    i = bisect(luck, n)
    print(max(0,(n-luck[i-1])*(luck[i]-n)-1))