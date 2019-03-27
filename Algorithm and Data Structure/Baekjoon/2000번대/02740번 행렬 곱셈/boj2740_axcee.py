
def matprod(a, b) :
    return [[sum(a[i][j]*b[j][k] for j in range(len(b))) for k in range(len(b[0]))] for i in range(len(a))]

def printmat(mat) :
    for row in mat :
        print(' '.join(str(x) for x in row))

i, j = map(int, input().split())
a = [[int(x) for x in input().split()] for r in range(i)]
j, k = map(int, input().split())
b = [[int(x) for x in input().split()] for r in range(j)]

printmat(matprod(a, b))