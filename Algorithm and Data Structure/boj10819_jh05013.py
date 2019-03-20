def calc(L):
    return sum(abs(L[i]-L[i+1]) for i in range(n-1))

n = int(input())
A = sorted(map(int,input().split()))
mid = n//2
B = [A[mid]] + [None]*(n-1)
B[1::2] = A[:mid]
B[2::2] = A[-1:mid:-1]
if n%2 == 1:
    C = B[:]
    for i in range(1, n, 2): C[i], C[i+1] = C[i+1], C[i]
else:
    mid-= 1
    C = [A[mid]] + [None]*(n-1)
    C[1::2] = A[-1:mid:-1]
    C[2::2] = A[:mid]
print(max(calc(B), calc(C)))