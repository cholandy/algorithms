MIS = lambda: map(int,input().split())
b, c, d = MIS()
burger = sorted(MIS())
side = sorted(MIS())
drink = sorted(MIS())
setc = min(b,c,d)

cost = sum(burger) + sum(side) + sum(drink)
print(cost)
for i in range(setc):
    cost-= (burger[~i] + side[~i] + drink[~i])//10
print(cost)