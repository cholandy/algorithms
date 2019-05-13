def fibo(n):
    global zero, one
    if n==0:
        zero+=1
        return 0
    elif n==1:
        one+=1
        return 1
    else:
        return fibo(n-1)+fibo(n-2)

for tc in range(int(input())):
    zero,one=0,0
    a=int(input())
    fibo(a)
    print(zero, one)