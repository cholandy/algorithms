a = []
s = input()
for i in range(10):
	a.append(s.count(str(i)))
a[6] += a[9] + 1
a[6] //= 2
a[9] = a[6]
print(max(a))