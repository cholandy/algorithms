import sys;sys.stdin=open('input2.txt','r')
for tc in range(int(input())):
    n,m=map(int,input().split())
    grid=[[] for i in range(m)] 
    for i in range(m):
        a,b,c=map(int,input().split())
        grid[i]=[a,c,b]
    parent=list(range(n+1))
    def find_parent(x):
        if x==parent[x]:return x
        parent[x]=find_parent(parent[x])
        return parent[x]
    r=0
    [print(*i) for i in grid]           
    # print(f'#{tc+1} {r}')
    print()
print(2**20)