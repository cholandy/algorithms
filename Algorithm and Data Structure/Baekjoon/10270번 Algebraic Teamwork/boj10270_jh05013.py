def factorial(n):
    res = 1
    for i in range(1, n+1):
        res = (res*i)%1000000007
    return res

for TEST in range(int(input())):
    n = int(input())
    print(factorial(n)-1)