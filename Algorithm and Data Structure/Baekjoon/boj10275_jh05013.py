for TEST in range(int(input())):
    n, a, b = map(int,input().split())
    print(bin(a).count('1')+bin(b).count('1')-1)