N, M = map(int, input().split())
MAP = []
camera = []
camera_dir = [4,2,4,4,1]
camera_dir_idx = [
    [[[1,0]], [[-1,0]], [[0,1]], [[0,-1]]],
    [[[1,0],[-1,0]], [[0,1],[0,-1]]],
    [[[1,0],[0,1]], [[0,1],[-1,0]], [[0,-1],[-1,0]], [[1,0],[0,-1]]],
    [[[0,-1],[1,0],[0,1]], [[1,0],[0,1],[-1,0]], [[0,1],[-1,0],[0,-1]], [[-1,0],[0,-1],[1,0]]],
    [[[0,-1],[1,0],[0,1],[-1,0]]],
]
block = []

for i in range(N):
    MAP.append(list(input().split()))
    for j in range(M):
        for k in range(1, 7):
            if MAP[i][j] == str(k) and MAP[i][j] != '6':
                camera.append([k, i, j])
                break
            elif MAP[i][j] == '6':
                block.append([i,j])
                break

def deepcopy(l):
    return [l[i][:] for i in range(len(l))]

def surveil(row,  m):
    for i in range(len(camera)):
        for j in range(1, 6):
            if camera[i][0] == j:
                c_dir = camera_dir_idx[j-1][row[i]]
                cur_x = camera[i][1]
                cur_y = camera[i][2]
                for v in c_dir:
                    for k in range(1, max(N,M)+1):
                        if ( cur_x+v[0]*k < N and cur_x+v[0]*k >=0 and
                         cur_y+v[1]*k < M and cur_y+v[1]*k >=0):
                            if m[cur_x+v[0]*k][cur_y+v[1]*k] == '0':
                                m[cur_x+v[0]*k][cur_y+v[1]*k] = '#'
                            elif m[cur_x+v[0]*k][cur_y+v[1]*k] == '6':
                                break
                break

greedy = [-1 for i in range(len(camera))]
sagak = []
def full(depth):
    if len(camera) == depth:
        _m = deepcopy(MAP)
        surveil(greedy, _m)
        cnt = 0
        for j in range(N):
            cnt += _m[j].count('0')
        sagak.append(cnt)
    else:
        for i in range(camera_dir[camera[depth][0]-1]):
            greedy[depth] = i
            full(depth+1)
full(0)

print(min(sagak))

