import sys;sys.stdin=open('input1.txt','r')

def gethome(x,y,k):
    ret=0
    for i in range(x-k+1,x+k):
        if 0<=i<n:
            for j in range(y-k+1+abs(x-i),y+k-abs(x-i)):
                if 0<=j<n and city[i][j]==1:
                    ret+=1 
    if ret*m<toco:return 0
    else:return ret

for t in range(int(input())):
    n,m=map(int,input().split())
    city=[list(map(int,input().split())) for i in range(n)]
    home_cnt=sum(city[i][j] for i in range(n) for j in range(n) if city[i][j]==1)
    cost=[i**2+(i+1)**2 for i in range(21) if home_cnt*m >i**2+(i+1)**2]
    ans=0
    
    k_cnt=len(cost)
    if k_cnt==21:
        print("#{} {}".format(t+1, home_cnt))
        continue
    for k in range(k_cnt-1,-1,-1):
        toco=cost[k]
        for i in range(n):
            for j in range(n):
                ret=gethome(i,j,k+1)
                if ret>ans:
                    ans=ret
    print("#{} {}".format(t+1, ans))