
def sol(k, sd) :
    a = sd.index(max(sd))
    b = (a-1)%6 if sd[(a-1)%6] > sd[(a+1)%6] else (a+1)%6
    c = (a+3)%6
    d = (b+3)%6
    return k * (sd[a]*sd[b] - sd[c]*sd[d])

k = int(input())
sd = [int(input().split()[1]) for x in range(6)]
print(sol(k, sd))
