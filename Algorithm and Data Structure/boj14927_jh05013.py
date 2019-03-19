def simul(n):
	def press(i, j):
		for ni,nj in (i,j), (i-1,j), (i+1,j), (i,j-1), (i,j+1):
			if 0<=ni<X and 0<=nj<X: game[ni][nj] = not game[ni][nj]
	move = 0
	game = [row[:] for row in grid]
	for i in range(X):
		if n%2: press(0, i); move+= 1
		n//= 2
	for i in range(1, X):
		for j in range(X):
			if game[i-1][j]: press(i,j); move+= 1
	if True in game[-1]: return 999
	return move

input = raw_input
range = xrange
X = int(input())
grid = [map(int,input().split()) for i in range(X)]
res = min(simul(i) for i in range(2**X))
print(-1 if res==999 else res)
