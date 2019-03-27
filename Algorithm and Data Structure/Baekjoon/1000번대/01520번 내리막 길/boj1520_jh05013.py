def get(x,y,h):
    if 0<=x<len(H[0]) and 0<=y<len(H):
        if grid[y][x] == h:
            return 0
        return H[y][x]
    return 0

h,w = map(int,input().split())
grid = [[0]*w for j in range(h)]
heights = []
for j in range(h):
    line = list(map(int,input().split()))
    for i in range(w):
        heights.append((line[i], i, j))
        grid[j][i] = line[i]
heights.sort(reverse=True)
H = [[0]*w for j in range(h)]

H[0][0] = 1
for a,b,c in heights:
    if b==c==0:
        continue
    h = grid[c][b]
    if h >= grid[0][0]:
        continue
    H[c][b] = get(b-1,c,h)+get(b+1,c,h)+get(b,c+1,h)+get(b,c-1,h)
print(H[-1][-1])