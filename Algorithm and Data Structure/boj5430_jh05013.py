for T in range(int(input())):
    p = input()
    n = int(input())
    s = input()
    if s == "[]": x = []
    else: x = list(map(int,s[1:-1].split(',')))
    i = 0
    j = n-1
    imode = True
    for c in p:
        if c == "R": imode = not imode
        elif imode: i+= 1
        else: j-= 1
    if i > j+1: print("error")
    elif i > j: print("[]")
    elif imode: print("["+','.join(map(str,x[i:j+1]))+"]")
    elif i > 0: print("["+','.join(map(str,x[j:i-1:-1]))+"]")
    else: print("["+','.join(map(str,x[j::-1]))+"]")
