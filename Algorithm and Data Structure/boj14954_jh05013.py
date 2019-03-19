n = int(input())
while 1:
    n = sum(int(d)**2 for d in str(n))
    if n == 1: print("HAPPY"); break
    if n == 4: print("UNHAPPY"); break