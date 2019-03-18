key = input()
devil = input()
angel = input()
kd = [[0]*len(devil) for i in range(len(key))]
ka = [[0]*len(angel) for j in range(len(key))]

for j in range(len(devil)):
    kd[0][j] = kd[0][j-1]
    if devil[j] == key[0]:
        kd[0][j]+= 1
    ka[0][j] = ka[0][j-1]
    if angel[j] == key[0]:
        ka[0][j]+= 1
for i in range(1, len(key)):
    for j in range(i, len(devil)):
        kd[i][j] = kd[i][j-1]
        if devil[j] == key[i]:
            kd[i][j]+= ka[i-1][j-1]
        ka[i][j] = ka[i][j-1]
        if angel[j] == key[i]:
            ka[i][j]+= kd[i-1][j-1]
print(kd[-1][-1]+ka[-1][-1])