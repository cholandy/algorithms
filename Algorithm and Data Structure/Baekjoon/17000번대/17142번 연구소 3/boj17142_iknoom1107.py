from itertools import combinations as cb
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
N,M = map(int,input().split())
g = [list(map(int,input().split())) for _ in range(N)]
virus = []
S = 0
ans = 10**9
for i in range(N):
	for j in range(N):
		if g[j][i] == 2: virus.append((i,j))
		if g[j][i] == 0: S += 1
for vrs in cb(virus,M):
	queue = list(vrs)
	vst = [[-1]*N for _ in range(N)]
	cnt = 0
	for x,y in queue: vst[y][x] = 0
	for x,y in queue:
		for i in range(4):
			X,Y = x+dx[i], y+dy[i]
			if 0<=X<N and 0<=Y<N and vst[Y][X]<0 and g[Y][X]!=1:
				if g[Y][X] == 0: cnt += 1
				vst[Y][X] = vst[y][x] + 1
				if cnt == S: ans = min(ans, vst[Y][X]); break
				queue.append((X,Y))
if S == 0: ans = 0
print(ans if ans!=10**9 else -1)