for tc in range(int(input())):
    n=int(input())
    def f(x):
        i=2
        while i*i<=x:
            if x%i==0:
                return 0
            i+=1
        return 1
    for i in range((n+1)//2,n):
        if f(i) and f(n-i):
            break
    print(n-i,i)