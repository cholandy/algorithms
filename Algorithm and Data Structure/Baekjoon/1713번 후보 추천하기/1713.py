import sys
sys.stdin = open("input.txt",'r')
N=int(input())
reco=int(input())
recos=list(map(int,input().split()))
comp=[[i,0] for i in range(reco+1)]

aa=[]

def goodbye(arr):
    minimum=1000
    gg=[]
    for i in range(len(arr)):
        if arr[i][1]>0 and arr[i][1] <= minimum:
            minimum = arr[i][1]
    for o in range(len(arr)):
        if arr[o][1]==minimum:
            gg.append(o)
    return gg


for i in range(reco):
    if i <N and recos[i] not in aa:
        aa.append(recos[i])
        comp[recos[i]][1] +=1
        continue
    if i <N and recos[i] in aa:
        comp[recos[i]][1] +=1
        continue
    if i>=N and recos[i] not in aa:
        good=goodbye(comp)
        for h in range(N):
            if aa[h] in good:
                aa.pop(h)
                comp[aa[h]][1]=0
                break
        aa.append(recos[i])
        comp[recos[i]][1] +=1
        continue
    if i >=3 and recos[i] in aa:
        comp[recos[i]][1] +=1
print(comp)
print(aa)