a = [0 for _ in range(6)]
b = ((3, 1, 0, 5, 4, 2), (2, 1, 5, 0, 4, 3), (4, 0, 2, 3, 5, 1), (1, 5, 2, 3, 0, 4))
px = (0, 0, -1, 1)
py = (1, -1, 0, 0)
n, m, x, y, l = map(int, input().split())
d = [list(map(int, input().split())) for _ in range(n)]
for t in map(int, input().split()):
	t -= 1
	tx, ty = x + px[t], y + py[t]
	if tx < 0 or tx >= n or ty < 0 or ty >= m:
		continue
	x, y = tx, ty
	a = [a[b[t][i]] for i in range(6)]
	if d[x][y]:
		a[5], d[x][y] = d[x][y], 0
	else:
		d[x][y] = a[5]
	print(a[0])