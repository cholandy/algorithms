for _ in range(int(input())):
	n, m = map(int, input().split())
	while n:
		t = (m + n - 1) // n
		n, m = t * n - m, t * m
	print(t)