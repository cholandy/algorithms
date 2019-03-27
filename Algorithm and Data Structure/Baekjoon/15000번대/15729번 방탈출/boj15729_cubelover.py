n = int(input())
a = list(map(int, input().split()))
r = 0
for i in range(n):
	if a[i]:
		r += 1
		if i + 1 < n:
			a[i + 1] ^= 1
			if i + 2 < n:
				a[i + 2] ^= 1
print(r)