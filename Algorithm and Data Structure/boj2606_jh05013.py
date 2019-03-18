n = int(input())
ed = int(input())
connected = [None]+[[] for i in range(n)]
stack = [1]
infected = {1}

for i in range(ed):
    a,b = map(int,input().split())
    connected[a].append(b)
    connected[b].append(a)

while stack:
    now = stack.pop()
    for i in connected[now]:
        if i not in infected:
            infected.add(i)
            stack.append(i)
print(len(infected)-1)