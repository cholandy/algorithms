for _ in range(int(input())):
    a, b = map(int, input().split())
    while a != 0:
        c = b//a + int(bool(b%a))
        a,b = a*c-b, b*c
    print(c)
