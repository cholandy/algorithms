black = set()
for T in range(int(input())):
    x,y = map(int,input().split())
    for i in range(x,x+10):
        for j in range(y,y+10):
            black.add((i,j))
dia = 0
for i in range(-1,102):
    for j in range(-1,102):
        if (i,j) in black:
            continue
        for x,y in ((i-1,j),(i+1,j),(i,j-1),(i,j+1)):
            if (x,y) in black:
                dia+= 1
print(dia)