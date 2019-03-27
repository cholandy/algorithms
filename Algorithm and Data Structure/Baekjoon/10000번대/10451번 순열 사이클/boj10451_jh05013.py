for T in range(int(input())):
    n = int(input())
    p = [0]+list(map(int,input().split()))
    visited = [0]*(n+1)
    count = -1
    for i in range(n+1):
        if visited[i]: continue
        j = i
        count+= 1
        while not visited[j]:
            visited[j] = 1
            j = p[j]
    print(count)