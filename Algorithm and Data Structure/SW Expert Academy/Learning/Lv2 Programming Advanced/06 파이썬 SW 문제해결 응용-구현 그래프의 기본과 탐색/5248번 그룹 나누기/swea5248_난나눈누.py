import sys;sys.stdin=open('input1.txt','r')
def union(x,y):
    group[find_set(y)]=find_set(x)
    
def find_set(x):
    if group[x]!=x:
        group[x]=find_set(group[x])
    return group[x]

for tc in range(int(input())):
    n,m=map(int,input().split())
    team_request=list(map(int,input().split()))
    group=[i for i in range(n+1)]
    for i in range(len(team_request)//2):
        union(team_request[i*2],team_request[i*2+1])
    for i in range(1,n+1):
        group[i]=find_set(i)
    print(f'#{tc+1}', len(set(group[1:])))