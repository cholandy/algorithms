import sys;sys.stdin=open('input2.txt','r')

from heapq import heappush, heappop

for tc in range(int(input())):
    INF = float('inf')
    n,m=map(int,input().split()) # 노드의 수, 간선의 수
    min_distance = [INF]*(n+1)
    info = [[] for _ in range(n+1)]
    for i in range(m):
        start, next, weight = map(int, input().split()) # 출발점, 도착점, 가중치
        info[start].append([next, weight])
    departure, arrival =0,n
    priority_queue = []
    heappush(priority_queue, (0, departure)) # 시작점 힙에 넣기(가중치, 출발점)
    min_distance[departure] = 0
    while priority_queue:
        weight, now = heappop(priority_queue)
        if min_distance[now] < weight:continue # 현재 장소까지의 가중치보다 가중치가 더 클때는 넘어간다.
        for next, new_weight in info[now]:
            new_weight += weight
            if min_distance[next] > new_weight:
                min_distance[next] = new_weight
                heappush(priority_queue, (new_weight, next))
    print(f'#{tc+1} {min_distance[arrival]}')
