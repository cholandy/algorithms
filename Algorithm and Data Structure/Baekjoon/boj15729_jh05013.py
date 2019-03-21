n = int(input())
L = list(map(int,input().split()))
press = 0
for i in range(n):
    if L[i] == 0: continue
    press+= 1
    for j in range(i, i+3):
        if j < n: L[j] = 1-L[j]
print(press)