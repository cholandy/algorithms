m, n = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
d = list()
for i in range(n):
	for j in range(m):
		if a[i][j] == 1:
			d.append((i, j))
for i, j in d:
	if i > 0 and not a[i - 1][j]:
		a[i - 1][j] = a[i][j] + 1
		d.append((i - 1, j))
	if i + 1 < n and not a[i + 1][j]:
		a[i + 1][j] = a[i][j] + 1
		d.append((i + 1, j))
	if j > 0 and not a[i][j - 1]:
		a[i][j - 1] = a[i][j] + 1
		d.append((i, j - 1))
	if j + 1 < m and not a[i][j + 1]:
		a[i][j + 1] = a[i][j] + 1
		d.append((i, j + 1))
if sum(map(lambda x: x.count(0), a)):
	print(-1)
else:
	print(max(map(max,a))-1)