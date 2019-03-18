s = input()
n = [3,3,3,3,3,4,3,4]
l = []
for i in range(8):
	for j in range(int(n[i])):
		l.append(i+3)
sum = 0
for i in s:
	sum += l[ord(i) - ord('A')]
print (sum)