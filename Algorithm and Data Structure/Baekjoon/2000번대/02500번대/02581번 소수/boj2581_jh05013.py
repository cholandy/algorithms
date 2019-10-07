def prime(n):
    if n==1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True

s = 0
minv = 10000
for i in range(int(input()),int(input())+1):
    if prime(i):
        s+= i
        if minv > i:
            minv = i
if minv == 10000:
    print(-1)
else:
    print(s)
    print(minv)