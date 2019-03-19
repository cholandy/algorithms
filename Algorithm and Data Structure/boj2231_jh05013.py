def create(n):
    if n<0:
        return -1
    return n+sum(map(int,str(n)))

n = int(input())
for i in range(n-60,n):
    if create(i) == n:
        print(i)
        break
else:
    print(0)