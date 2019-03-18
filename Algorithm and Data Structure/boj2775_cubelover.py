d = [[0 for _ in range(15)] for _ in range(15)]
for j in range(1, 15):
    d[0][j] = j
for i in range(1, 15):
    for j in range(1, 15):
        d[i][j] = d[i - 1][j] + d[i][j - 1]
for _ in range(int(input())):
    print(d[int(input())][int(input())])