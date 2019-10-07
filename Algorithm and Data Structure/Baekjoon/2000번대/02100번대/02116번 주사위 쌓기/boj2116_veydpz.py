flip = [5,3,4,1,2,0]

n = int(input())
dice = []
for i in range(n):
	dice.append(list(map(int,input().split())))

ans = []
for i in range(6):
	arr = []
	arr.append(dice[0][i])
	for j in range(n):
		k = dice[j].index(arr[-1])
		arr.append(dice[j][flip[k]])
	s = 0
	for j in range(n):
		if(arr[j] != 6 and arr[j+1] != 6):
			s += 6
		elif(arr[j] != 5 and arr[j+1] != 5):
			s += 5
		else:
			s += 4
	ans.append(s)

print(max(ans))