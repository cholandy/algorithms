n = int(input())
seq = list(map(int,input().split()))
maxg = float('inf')
u = -1
for i in range(n-1):
    S = seq[i] + seq[i+1]
    if 3*S < maxg: maxg = 3*S; u = i
    if i == n-2: continue
    S+= seq[i+2]
    if 2*S < maxg: maxg = 2*S; u = i
print(u)