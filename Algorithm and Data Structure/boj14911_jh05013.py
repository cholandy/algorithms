L = list(map(int,input().split()))
targ = int(input())
tups = set()
for i in range(len(L)):
    for j in range(i+1, len(L)):
        if L[i] + L[j] == targ: tups.add((L[i], L[j]))
for i, j in sorted(tups): print(i, j)
print(len(tups))