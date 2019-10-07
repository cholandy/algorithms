for i in range(int(input())):
	a,b = map(int,input().split())
	i=b-a
	if i**.5%1==0:
		print(round(2*i**.5-1))
	else:
		print(round(2*i**.5-.5))