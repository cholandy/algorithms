n = int(input())
parent = list(map(int,input().split()))
delete = int(input())
son = [set() for i in range(n)]

for i in range(n):
    p = parent[i]
    if p != -1:
        son[p].add(i)
    else:
        root = i

def countleaf(i):
    if len(son[i]) == 0:
        return 1
    res = 0
    for s in son[i]:
        res+= countleaf(s)
    return res
        
if parent[delete] == -1:
    print(0)
else:
    son[parent[delete]].remove(delete)
    print(countleaf(root))
