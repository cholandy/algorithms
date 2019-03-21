from sys import stdin
input = stdin.readline

for T in range(int(input())):
    p, m, f, c = map(int,input().split())
    ini = m//p
    chicken = 0
    coupon = ini*f
    get = 1
    while get:
        get = coupon//f
        chicken+= get
        coupon%= f
        coupon+= get*c
    print(chicken - ini - ini*c//f)