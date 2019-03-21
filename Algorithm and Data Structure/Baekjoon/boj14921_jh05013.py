n = int(input())
prop = sorted(map(int,input().split()))
best = float('inf')
i = 0
j = n-1
while i < j:
    mix = prop[i] + prop[j]
    if abs(mix) < abs(best): best = mix
    if mix < 0: i+= 1
    else: j-= 1
print(best)