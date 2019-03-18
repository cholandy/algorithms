for i in range(int(input())):
    a,b = map(int, input().split())
    n = (a**(b%4+4))%10
    print(n if n else 10)