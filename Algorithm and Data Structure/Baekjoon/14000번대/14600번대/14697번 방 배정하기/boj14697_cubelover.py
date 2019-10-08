a, b, c, d = map(int, input().split())
for i in range(101):
	for j in range(151):
		if i * c + j * b <= d and (d - i * c - j * b) % a == 0:
			print(1)
			exit(0)
print(0)