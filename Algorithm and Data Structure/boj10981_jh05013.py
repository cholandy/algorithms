n,k = map(int,input().split())
univ = {}

for i in range(n):
    a,b,c,d = input().split()
    c,d = int(c), -int(d)
    T = (c,d,b)
    if a not in univ or T > univ[a]:
        univ[a] = T
for b,c,d in sorted(univ.values(), reverse=True)[:k]:
    print(d)