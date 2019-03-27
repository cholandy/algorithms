a=[]
for i in range(int(input())):
	t=input().split()
	if t[0]=="push_front":
		a.insert(0,t[1])
	if t[0]=="push_back":
		a.append(t[1])
	if t[0]=="pop_front":
		if a:
			print(a[0])
			del a[0]
		else:
			print(-1)
	if t[0]=="pop_back":
		if a:
			print(a[len(a)-1])
			del a[len(a)-1]
		else:
			print(-1)
	if t[0]=="size":
		print(len(a))
	if t[0]=="empty":
		print(0 if a else 1)
	if t[0]=="front":
		if a:
			print(a[0])
		else:
			print(-1)
	if t[0]=="back":
		if a:
			print(a[len(a)-1])
		else:
			print(-1)