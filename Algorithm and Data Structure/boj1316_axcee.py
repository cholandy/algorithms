def gr(s) :
    d = {}
    for i, c in enumerate(s) :
        if c in d and i-d[c] != 1 :
            return False
        d[c] = i
    return True

n = int(input())
s = 0
for i in range(n) :
    s += gr(input())
print(s)