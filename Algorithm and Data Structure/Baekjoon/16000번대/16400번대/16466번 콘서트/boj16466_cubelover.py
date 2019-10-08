import sys
input = sys.stdin.readline
input()
a = sorted(map(int, input().split()))
i = 1
for x in a:
	if i != x:
		break
	i += 1
print(i)