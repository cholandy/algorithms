L = [int(input()) for T in range(int(input()))]
zero = 0
one = L[0]
two = 0

for i in range(1,len(L)):
    cur = L[i]
    zero, one, two = max(zero,one,two), zero+cur, one+cur
print(max(zero,one,two))