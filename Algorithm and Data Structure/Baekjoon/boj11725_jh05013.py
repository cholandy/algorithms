adj = [None]+[set() for i in range(int(input()))]
for T in range(len(adj)-2):
    a,b = map(int,input().split())
    adj[a].add(b)
    adj[b].add(a)
stack = [1]
parent = [-1]*len(adj)
parent[1] = 0
while stack:
    now = stack.pop()
    for a in adj[now]:
        if parent[a] == -1:
            parent[a] = now
            stack.append(a)
for i in range(2,len(parent)):
    print(parent[i])