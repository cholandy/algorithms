import sys
input=sys.stdin.readline
for tc in range(int(input())):
	a=input().split()
	while True:
		s=input().split()
		if len(s)>3:
			break
		a=[x for x in a if x != s[2]]
	print(' '.join(a))