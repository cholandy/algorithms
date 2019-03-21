m,n = map(int,input().split())
prime = [1]*(n+1)
prime[0] = 0
prime[1] = 1
for i in range(2,n+1):
    if i>=m and prime[i]:
        print(i)
    if prime[i]:
        for j in range(2*i,n+1,i):
            prime[j] = 0
