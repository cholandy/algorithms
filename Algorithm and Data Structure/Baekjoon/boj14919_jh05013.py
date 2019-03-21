from decimal import Decimal as D
m = int(input())
count = [0]*m
for x in list(map(D, input().split())): count[int(x*m)]+= 1
print(*count)