from sys import stdin
MIS = lambda: map(int,stdin.readline().split())
n, m = MIS()
card = list(range(1, n+1))
for i in range(m):
    a, b = MIS()
    card[a-1]+= 1
    card[b-1]-= 1
if sorted(card) == list(range(1, n+1)): print(*card)
else: print(-1)