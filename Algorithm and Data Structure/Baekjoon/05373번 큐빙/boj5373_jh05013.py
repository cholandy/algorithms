import sys
sys.stdin = open('input.txt', 'r')

def moveface(a11, a12, a13, a21, a22, a23, a31, a32, a33):
    c[a11], c[a12], c[a13], c[a21], c[a22], c[a23], c[a31], c[a32], c[a33] = \
        c[a31], c[a21], c[a11], c[a32], c[a22], c[a12], c[a33], c[a23], c[a13]

def moveside(u1, u2, u3, r1, r2, r3, d1, d2, d3, l1, l2, l3):
    c[u1], c[u2], c[u3], c[r1], c[r2], c[r3], c[d1], c[d2], c[d3], c[l1], c[l2], c[l3] = \
        c[l1], c[l2], c[l3], c[u1], c[u2], c[u3], c[r1], c[r2], c[r3], c[d1], c[d2], c[d3]

note = "LFRBUD"
faces = [[9, 10, 11, 21, 22, 23, 33, 34, 35],
         [12, 13, 14, 24, 25, 26, 36, 37, 38],
         [15, 16, 17, 27, 28, 29, 39, 40, 41],
         [18, 19, 20, 30, 31, 32, 42, 43, 44],
         [0, 1, 2, 3, 4, 5, 6, 7, 8],
         [45, 46, 47, 48, 49, 50, 51, 52, 53]]
sides = [[0, 3, 6, 12, 24, 36, 45, 48, 51, 44, 32, 20],
         [6, 7, 8, 15, 27, 39, 47, 46, 45, 35, 23, 11],
         [8, 5, 2, 18, 30, 42, 53, 50, 47, 38, 26, 14],
         [2, 1, 0, 9, 21, 33, 51, 52, 53, 41, 29, 17],
         [20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9],
         [36, 37, 38, 39, 40, 41, 42, 43, 44, 33, 34, 35]]

for TEST in range(int(input())):
    c = list("w"*9 + "gggrrrbbbooo"*3 + "y"*9)
    input()
    for x, y in input().split():
        fi = note.find(x)
        rep = 1 if y == "+" else 3
        for i in range(rep): moveface(*faces[fi]); moveside(*sides[fi])
    for i in range(0, 9, 3): print(c[i]+c[i+1]+c[i+2])