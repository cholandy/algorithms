n = int(input())
m = int(input())
vip = [0]+[int(input()) for i in range(m)]+[n+1]
fib = [1,1]
for i in range(40): fib.append(fib[-1] + fib[-2])
res = 1
for i in range(m+1): res*= fib[vip[i+1]-vip[i]-1]
print(res)