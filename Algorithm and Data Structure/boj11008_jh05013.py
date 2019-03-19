for T in range(int(input())):
    s, p = input().split()
    print(len(s)-(len(p)-1)*s.count(p))