d,a,b = map(int,input().split())
k = d/(a**2+b**2)**0.5
print(int(a*k), int(b*k))