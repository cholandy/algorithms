n = int(input())
m = [list(map(int,input().split())) for i in range(n)]
a = [0]*n

def update(unit):
    au = [0]*n
    for i in range(n):
        for j in range(i+1, n):
            if m[i][j]&unit: au[i], au[j] = unit, unit
    for i in range(n):
        a[i]+= au[i]
u = 1
while u < 10**9:
    update(u)
    u<<=1
print(' '.join(map(str,a)))