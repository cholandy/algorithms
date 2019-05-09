from collections import deque
MAX_T = 500000
visited = [[-1]*(MAX_T+1) for _ in range(2)]

def bfs(soobin):
    q = deque()
    q.append((soobin, 0))
    visited[0][soobin]=0

    while len(q):
        cur, t = q.popleft()
        flag = t%2
        for next in [cur+1, cur-1, cur*2]:
            if 0<=next and next<=MAX_T and visited[1-flag][next]==-1:
                visited[1-flag][next]=t+1
                q.append((next, t+1))

def find(sister):
    t = 0
    cur = sister
    flag = 0
    while cur<=MAX_T:
        if visited[flag][cur]!=-1 and visited[flag][cur]<=t:
            return t
        flag=1-flag
        t+=1
        cur+=t
    return -1

soobin, sister = [int(x) for x in input().split()]
bfs(soobin)
print(find(sister))