class gear:
    def __init__(self,stat):
        self.state=stat
    def turnself(self,d):
        if d==1:
            self.state=self.state[-1]+self.state[:-1]
        elif d==-1:
            self.state=self.state[1:]+self.state[0]
gears=[]
for i in range(4):
    gears.append(gear(input()))
n=int(input())
for i in range(n):
    ismove=[False]*4
    x,d=list(map(int,input().split()))
    x-=1
    ismove[x]=d
    for j in range(x+1,4,1):
        if ismove[j-1] and gears[j-1].state[2]!=gears[j].state[6]:
            ismove[j]=-ismove[j-1]
    for j in range(x-1,-1,-1):
        if ismove[j+1] and gears[j].state[2]!=gears[j+1].state[6]:
            ismove[j]=-ismove[j+1]
    for j in range(4):
        if ismove[j]:
            gears[j].turnself(ismove[j])
print(sum([int(gears[i].state[0])*(2**i) for i in range(4)]))
