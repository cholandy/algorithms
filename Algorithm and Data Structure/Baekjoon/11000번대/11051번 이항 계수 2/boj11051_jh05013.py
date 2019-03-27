n,m = map(int,input().split())
cur = 1
for i in range(1,m+1):
    cur = cur*(n-i+1)//i
print(cur%10007)