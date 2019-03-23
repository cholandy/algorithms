import queue
 
n, m = [int(x) for x in input().split()]
 
q = queue.Queue()
 
q.put([n,0])
 
while(not q.empty()):
    here, cnt = q.get()
 
    if here == m:
        print(cnt + 1)
        exit(0)
 
    if here * 2 <= m:
        q.put([here * 2, cnt + 1])
    if here * 10 + 1 <= m:
        q.put([here * 10 + 1, cnt + 1])
 
print(-1)
