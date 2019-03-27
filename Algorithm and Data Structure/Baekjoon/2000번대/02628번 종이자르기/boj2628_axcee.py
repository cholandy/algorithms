v, h = [0], [0]
x, y = map(int, input().split())
v.append(y); h.append(x)
n = int(input())
for i in range(n) :
    k, p = map(int, input().split())
    if k == 0 : v.append(p)
    else : h.append(p)
v.sort(); h.sort()
mx = max(h[i+1]-h[i] for i in range(len(h)-1))
my = max(v[i+1]-v[i] for i in range(len(v)-1))
print(mx*my)
