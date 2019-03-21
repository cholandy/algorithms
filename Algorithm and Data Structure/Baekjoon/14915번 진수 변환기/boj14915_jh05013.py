m, n = map(int,input().split())
if not m: print(0); exit()
res = []
while m:
    c = m%n
    res.append(str(c) if c<=9 else chr(ord("A")+c-10))
    m//= n
print(''.join(reversed(res)))