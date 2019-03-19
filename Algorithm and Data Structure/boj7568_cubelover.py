n=int(input())
a=[list(map(int,input().split())) for i in range(n)]
for x in a:
	r=1
	for y in a:
		if x[0]<y[0] and x[1]<y[1]:
			r+=1
	print(r, end = ' ')