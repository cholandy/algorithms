from decimal import Decimal as D

def addval(dic, key, v):
    if key not in dic: dic[key] = v
    else: dic[key]+= v

n, m, b = map(int,input().split())
m = D(m)/100
b = D(b)/100
prob = {D(1): D(1)}
for i in range(n):
    pi, ri = map(D, input().split())
    pi/= 100
    newprob = {}
    for money in prob:
        if money <= b: addval(newprob, money, prob[money])
        else:
            addval(newprob, money*(1-m), prob[money]*(1-pi))
            addval(newprob, money*(1+m*(ri-1)), prob[money]*pi)
    prob = newprob

res = D(0)
for p in prob:
    if p > 1: res+= prob[p]
print(res*100)