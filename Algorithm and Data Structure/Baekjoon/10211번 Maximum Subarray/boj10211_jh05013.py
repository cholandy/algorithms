for T in range(int(input())):
    n = int(input())
    X = list(map(int,input().split()))
    cur = 0
    opt = max(X)
    for a in X:
        if cur >= 0:
            cur+= a
        else:
            cur = a
        opt = max(opt, cur)
    print(opt)
    