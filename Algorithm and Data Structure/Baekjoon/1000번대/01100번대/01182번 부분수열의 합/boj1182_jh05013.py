def SS(i, s):
    if i == n:
        return 1 if s==0 else 0
    return SS(i+1,s)+SS(i+1,s-q[i])

n,s = map(int,input().split())
q = list(map(int,input().split()))
ANS = SS(0,s)
print(ANS-1 if s==0 else ANS)