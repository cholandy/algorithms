n = int(input())
t = []
p = []
opt = [0]*(n+1) # best, last consult until i
for i in range(n):
    a, b = map(int,input().split())
    t.append(a)
    p.append(b)
for i in range(n):
    opt[i] = opt[i-1]
    for j in range(i+1):
        if j+t[j]-1 == i:
            opt[i] = max(opt[i], opt[j-1]+p[j])
print(max(opt))