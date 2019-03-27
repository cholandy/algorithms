W, H = map(int, input().split())
grid = [[0]*W for i in range(H)]
N, M = map(int, input().split())
c = 'SENW'
robo = {}
for i in range(N):
	x, y, head = map(str, input().split())
	y, x = int(y), int(x)
	robo[i+1] = [y-1, x-1]
	grid[y-1][x-1] = [i+1, head]
for i in range(M):
	robonum, command, repeat = map(str, input().split())
	robonum = int(robonum)
	repeat = int(repeat)
	ry, rx = map(int, robo.get(robonum))
	robohead = grid[ry][rx][1]
	if command in 'RL':
		for j in range(repeat % 4):
			grid[ry][rx][1] = c[(c.index(robohead)-1)%4] if command == 'R' else c[(c.index(robohead)+1)%4]
			robohead = grid[ry][rx][1]
	if command == 'F':
		dy = [-1, 0, 1, 0]
		dx = [0, 1, 0, -1]
		for j in range(repeat):
			try:
				rdy = dy[c.index(robohead)]
				rdx = dx[c.index(robohead)]
				if ry + rdy == -1 or rx + rdx == -1:
					raise IndexError
				if grid[ry+rdy][rx+rdx] != 0:
					robonum2 = grid[ry+rdy][rx+rdx][0]
					print("Robot {} crashes into robot {}".format(robonum, robonum2))
					exit()
				else:
					grid[ry][rx], grid[ry+rdy][rx+rdx] = 0, [robonum, robohead]		
					ry += rdy
					rx += rdx
					robo[robonum] = [ry, rx]
			except IndexError:
				print("Robot {} crashes into the wall".format(robonum))
				exit()
print("OK")
