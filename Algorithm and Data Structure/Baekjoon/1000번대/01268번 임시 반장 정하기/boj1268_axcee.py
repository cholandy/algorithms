import sys; input = lambda: sys.stdin.readline().rstrip()

def sol(n, std) :
    cls = [[[] for c in range(9)] for g in range(5)]
    for i, st in enumerate(std) :
        for g in range(5) :
            cls[g][st[g]-1].append(i)
    v = [[False for i in range(n)] for j in range(n)]
    for g in range(5) :
        for c in range(9) :
            t = cls[g][c]
            for i in range(len(t)) :
                for j in range(i+1, len(t)) :
                    v[t[i]][t[j]] = True
                    v[t[j]][t[i]] = True
    v = [sum(s) for s in v]
    return v.index(max(v)) + 1


n = int(input())
std = [list(map(int, input().split())) for i in range(n)]
print(sol(n, std))