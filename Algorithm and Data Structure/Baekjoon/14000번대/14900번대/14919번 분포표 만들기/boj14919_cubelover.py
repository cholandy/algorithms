n = int(input())
a = [0] * n
for x in input().split():
	a[int(float(x) * 1000000 + .5) * n // 1000000] += 1
print(*a)