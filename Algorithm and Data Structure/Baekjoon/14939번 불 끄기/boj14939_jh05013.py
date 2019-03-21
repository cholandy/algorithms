def simul(n):
	def press(i, j):
		for ni,nj in (i,j), (i-1,j), (i+1,j), (i,j-1), (i,j+1):
			if 0<=ni<10 and 0<=nj<10: game[ni][nj] = not game[ni][nj]
	move = 0
	game = [row[:] for row in grid]
	for i in range(10):
		if n%2: press(0, i); move+= 1
		n//= 2
	for i in range(1, 10):
		for j in range(10):
			if game[i-1][j]: press(i,j); move+= 1
	if True in game[-1]: return 999
	return move

grid = []
for i in range(10):
	s = input()
	row = []
	for c in s: row.append(c=="O")
	grid.append(row)
res = min(simul(i) for i in range(1024))
print(-1 if res==999 else res)
