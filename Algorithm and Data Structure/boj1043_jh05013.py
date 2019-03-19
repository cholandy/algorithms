MIS = lambda: map(int,input().split())
n, m = MIS()
t, *truth = MIS()
truth = set(truth)
party = []
for i in range(m):
    t, *P = MIS()
    party.append(set(P))
for i in range(m):
    for P in party:
        if truth&P: truth|= P
print(sum(not truth&P for P in party))