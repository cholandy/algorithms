from sys import stdin, stdout, setrecursionlimit

setrecursionlimit(10**6)
buf = map(int, stdin.read().split())
t = next(buf)
cost, prev, flag, time = None, None, None, None


def initialize(n, k): return (
    [None]+[next(buf) for _ in range(n)],
    [[] for _ in range(n+1)],
    [False for _ in range(n+1)],
    [0 for _ in range(n+1)]
)


def build(b):
    if not flag[b]:
        flag[b] = True
        time[b] = max(map(build, prev[b]), default=0)+cost[b]
    return time[b]


result = []
for i in range(t):
    n, k = next(buf), next(buf)
    cost, prev, flag, time = initialize(n, k)
    for j in range(k):
        a, b = next(buf), next(buf)
        prev[b].append(a)
    result.append(build(next(buf)))
stdout.write("\n".join(map(str, result))+"\n")
