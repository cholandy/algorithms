n = int(input())
carpet = [[0]*501 for i in range(501)]
for i in range(n):
    x1, y1, x2, y2 = map(int,input().split())
    for y in range(y1, y2):
        for x in range(x1, x2): carpet[y][x] = 1
print(sum(map(sum, carpet)))