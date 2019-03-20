import itertools
n = int(input())
r = 0
for x in itertools.permutations(map(int, input().split())):
    r = max(r, sum(abs(x[i] - x[i + 1]) for i in range(n - 1)))
print(r)