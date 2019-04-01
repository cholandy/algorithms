from collections import deque

def cal(v,p):
    if p==0:
        v+=1
    elif p==1:
        v-=1
    elif p==2:
        v*=2
    else:
        v-=10
    return v

for tc in range(int(input())):
    n,m=map(int,input().split())
    visited=[0]*1000001
    cnt=0
    Q=deque()
    Q.append((n,cnt))
    visited[n]=1
    while Q:
        a,b=Q.popleft()
        if a==m:
            print(f'#{tc+1} {b}')
            break
        for i in range(4):
            new_a=cal(a,i)
            if new_a>1000000 or new_a<1:continue
            if not visited[new_a]:
                visited[new_a]=1
                Q.append((new_a,b+1))