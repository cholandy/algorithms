n = int(input())
poke = []
evo = []
for i in range(n):
    poke.append(input())
    a, b = map(int,input().split())
    evo.append(max(0, b-2)//(a-2))
maxr = 0
best = ''
for i in range(n):
    if evo[i] > maxr:
        maxr = evo[i]
        best = poke[i]
print(sum(evo))
print(best)