import sys
n = int(sys.stdin.readline())
a = []
for i in range(n):
    a.append(int(sys.stdin.readline()))

d = [[0]*3 for _ in range(n+1)]

for k in range(n):
    d[k][0] = max(d[k-1][0],d[k-1][1],d[k-1][2])
    d[k][1] = d[k-1][0]+a[k]
    d[k][2] = d[k-1][1]+a[k]

result = max(d[n-1])
print(result)