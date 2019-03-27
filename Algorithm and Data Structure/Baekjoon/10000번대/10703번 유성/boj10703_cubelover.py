import sys
input=sys.stdin.readline
n,m=map(int,input().split())
s=[input() for i in range(n)]
t=n
for j in range(m):
	a=b=-n
	for i in range(n):
		if s[i][j]=='X':
			a=i
		if s[i][j]=='#':
			b=i
			break
	t=min(t,b-a-1)
print('\n'.join(''.join('#' if s[i][j]=='#' else 'X' if i-t>=0 and s[i-t][j]=='X' else '.' for j in range(m)) for i in range(n)))