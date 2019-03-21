import collections

def bfs(N,K,M,pipe):
    visit = [0 for i in range(M+N+2)]
    q = collections.deque()
    q.append((1,1))
    visit[1] = 1
    while q:
        cnt, now = q.popleft()
        if(now == N):
            return cnt
        else:
            for i in pipe[now]:
                if(visit[i] == 0):
                    ncnt = cnt
                    if(i <= N):
                        ncnt+=1
                    q.append((ncnt, i))
                    visit[i] = 1

    return -1



N, K, M = map(int, input().split())
pipe = [[] for i in range(M + N + 2)]


for i in range(1,M+1):
    inputline = list(map(int, input().split()))
    for j in range(K):
        nint = inputline[j]
        pipe[N+i].append(nint)
        pipe[nint].append(N+i)

print(bfs(N,K,M, pipe))




