def run(a, b):
    L = [a, b]
    while 1:
        new = L[-2]-L[-1]
        if new < 0: return L
        L.append(new)

n = int(input())
maxlen = 0
maxseq = []
for i in range(1, n+1):
    L = run(n, i)
    if len(L) > maxlen:
        maxlen = len(L)
        maxseq = L
print(maxlen)
print(*maxseq)