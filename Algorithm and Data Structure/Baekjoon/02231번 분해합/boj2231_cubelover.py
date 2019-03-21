n=int(input())
for i in range(n):
	t=j=i
	while j:
		t+=j%10
		j//=10
	if t==n:
		break
print(i if t==n else 0)