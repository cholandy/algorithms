n=int(input())
print(' '*(n-1)+'*')
for j in range(1,n):
	print(' '*(n-j-1)+'*'+' '*(2*j-1)+'*')