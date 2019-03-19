from bisect import bisect

p = list(range(246913))
p[1] = 0
for i in range(2,int(246913**0.5)+1):
    for j in range(i*i,246913,i):
        p[j] = 0
p = list(filter(None,p))
while True:
    n = int(input())
    if n == 0:
        break
    print(bisect(p,2*n)-bisect(p,n))