n = int(input())
k, p = map(int,input().split())
heap = [0] * (n+1)
used = [False] * (n+1)

# fill parents
pars = [p]
while pars[-1] != 1: pars.append(pars[-1]//2)
pars.pop(0)
i = 1
for slot in reversed(pars):
    heap[slot] = i; used[i] = True
    i+= 1
if used[k]: print(-1); exit()
heap[p] = k; used[k] = True

# fill sons
i = k+1
stack = [p]
while stack:
    slot = stack.pop()
    for news in slot*2, slot*2+1:
        if news > n: continue
        if i > n: print(-1); exit()
        heap[news] = i; used[i] = True
        i+= 1
        stack.append(news)

# fill rest
i = 1
for slot in range(1, n+1):
    if heap[slot]: continue
    while used[i]: i+= 1
    heap[slot] = i; used[i] = True

for i in range(1, n+1): print(heap[i])