n = int(input())
ary = list(map(int, input().split()))
ary2 = [-1]*len(ary)
a, b = map(int, input().split())
a, b = a-1, b-1
ary2[a] = 0
ary3 = [a]
p = 0
while 1:
	if len(ary3) == 0:
		break;
	k = ary3.pop(0)
	for i in range(k+ary[k], len(ary), ary[k]):
		if ary2[i] == -1 or ary2[i] > ary2[k] + 1:
			ary2[i] = ary2[k] + 1
			ary3.append(i)
	for i in range(k-ary[k], -1, -ary[k]):
		if ary2[i] == -1 or ary2[i] > ary2[k] + 1:
			ary2[i] = ary2[k] + 1
			ary3.append(i)
print(ary2[b])