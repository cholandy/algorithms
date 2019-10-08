MIS = lambda: map(int,input().split())

n, m, k = MIS()
A = [list(MIS()) for i in range(n)]
feed = [[5]*n for i in range(n)]
alive = [[[] for i in range(n)] for j in range(n)]
dead = [[0]*n for j in range(n)]
for i in range(m):
    x, y, age = MIS()
    alive[x-1][y-1].append(age)

def neigh(i, j):
    for ni in i-1, i, i+1:
        if not 0<=ni<n: continue
        for nj in j-1, j, j+1:
            if (ni != i or nj != j) and 0<=nj<n: yield ni, nj

for year in range(k):
    # Spring
    for i in range(n):
        for j in range(n):
            trees = alive[i][j]
            trees.sort()
            for k, age in enumerate(trees):
                if age == 999999: break
                if feed[i][j] < age: dead[i][j]+= age//2; trees[k] = 999999
                else: feed[i][j]-= age; trees[k]+= 1
            while trees and trees[-1] == 999999: trees.pop()
    # Summer + Winter and Autumn
    for i in range(n):
        for j in range(n):
            feed[i][j]+= dead[i][j] + A[i][j]
            dead[i][j] = 0
            for age in alive[i][j]:
                if age%5: continue
                for ni, nj in neigh(i, j): alive[ni][nj].append(1)

print(sum(len(alive[i][j]) for i in range(n) for j in range(n)))
