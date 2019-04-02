import sys;sys.stdin=open('input2.txt','r')

for tc in range(int(input())):
    n,m=map(int,input().split())
    d=[[] for i in range(m)] # 간선의 개수만큼 [] 생성
    for i in range(m):
        # a,b,c는 차례대로 출발노드, 도착노드, 가중치
        a,b,c=map(int,input().split())
        d[i]=(c,b,a)
    d.sort() # 가중치가 작은 것으로 정렬
    parent=list(range(n+1)) # 0 ~ n까지  
    # print(p)
    def find_parent(x):
        # 부모 노드를 찾아주는 함수
        if x==parent[x]:
            return x
        parent[x]=find_parent(parent[x])
        return parent[x]
    r=0
    for i in range(m): # 간선 개수만큼 돌아감 
        # 만약 도착노드의 부모노드와 출발노드의 부모노드가 다르다면
        if find_parent(d[i][1])!=find_parent(d[i][2]):
            # 도착노드의 부모노드를 출발노드의 부모노드로 재설정
            parent[find_parent(d[i][1])]=find_parent(d[i][2])
            # 가중치를 더해줌
            r+=d[i][0]
            
    print(f'#{tc+1} {r}')