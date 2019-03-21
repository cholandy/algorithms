from sys import stdin
input = stdin.readline
n = int(input())
left = [0]*(n+1)
right = [0]*(n+1)
image = [-1]*n
first = [99999]*n
last = [-1]*n
ind = [0]
root = set(range(1,n+1))
for i in range(n):
    a, b, c = map(int,input().split())
    left[a] = b
    right[a] = c
    if b in root:
        root.remove(b)
    if c in root:
        root.remove(c)
root = next(iter(root))

def search(node, h):
    if node == -1:
        return
    if left[node] != -1:
        search(left[node], h+1)
    image[ind[0]] = h
    first[h] = min(first[h], ind[0])
    last[h] = max(last[h], ind[0])
    ind[0]+= 1
    if right[node] != -1:
        search(right[node], h+1)

search(root, 0)
widest = -1
width = 0
for i in range(n):
    if first[i] == 99999:
        break
    if last[i]-first[i]+1 > width:
        width = last[i]-first[i]+1
        widest = i+1
print(widest, width)