for T in range(int(input())):
    parts = {}
    for i in range(int(input())):
        a,b = input().split()
        if b not in parts:
            parts[b] = 1
        else:
            parts[b]+= 1
    res = 1
    for i in parts.values():
        res*= i+1
    print(res-1)