import math

def star(s):
    ret = []
    for i in range(len(s)):
        ret.append(s[i]*3)
    for i in range(len(s)):
        ret.append(s[i]+" "*len(s)+s[i])
    for i in range(len(s)):
        ret.append(s[i]*3)
    return ret
    
s = "*"

n = int(input())
n //= 3

while n:
    n //= 3
    s = star(s)

print("\n".join(s))
