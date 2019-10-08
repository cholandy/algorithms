from random import random
D = [random() for i in range(26)]

def gen(s, l):
    # all l-components of s
    res = []; H = 0
    for i in range(l):
        H+= D[ord(s[i])-97]
    res.append(round(H,10))
    for i in range(l, len(s)):
        H+= D[ord(s[i])-97] - D[ord(s[i-l])-97]
        res.append(round(H,10))
    return res

from bisect import bisect_left as bl
def match(l):
    i, j = 0, 0
    aa, bb = sorted(gen(a,l)), gen(b,l)
    for h in bb:
        index = bl(aa, h)
        if index != len(aa) and aa[index] == h:
            return True
    return False

a = input()
b = input()
res = 0
for res in range(min(len(a),len(b)), -1, -1):
    if match(res):
        print(res)
        break
    