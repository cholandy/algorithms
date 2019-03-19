h = [int(input()) for i in range(9)]
h.sort()
target = sum(h)-100
broken = False
def find(h):
    target = sum(h)-100
    for i in range(9):
        for j in range(i+1,9):
            if h[i]+h[j] == target:
                return i,j
i,j = find(h)
for c in range(9):
    if c!=i and c!=j:
        print(h[c])