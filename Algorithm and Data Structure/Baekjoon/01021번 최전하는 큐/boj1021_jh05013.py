n, m = map(int,input().split())
goal = map(int,input().split())
queue = list(range(1,n+1))
res = 0
for i in goal:
    elim = queue.index(i)
    res+= min(elim, len(queue)-elim)
    queue = queue[elim+1:]+queue[:elim]
print(res)