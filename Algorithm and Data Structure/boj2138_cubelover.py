n = int(input())
a = list(map(int, input()))
b = list(map(int, input()))
c = list(a)
t1 = 0
for i in range(1, n):
	if a[i - 1] != b[i - 1]:
		a[i - 1] ^= 1
		a[i] ^= 1
		if i + 1 < n: a[i + 1] ^= 1
		t1 += 1
if a[n - 1] != b[n - 1]:
	t1 = 999999
c[0] ^= 1
c[1] ^= 1
t2 = 1
for i in range(1, n):
	if c[i - 1] != b[i - 1]:
		c[i - 1] ^= 1
		c[i] ^= 1
		if i + 1 < n: c[i + 1] ^= 1
		t2 += 1
if c[n - 1] != b[n - 1]:
	t2 = 999999
t = min(t1, t2)
print(-1 if t == 999999 else t)