import sys
sys.stdin = open("input.txt",'r')

N=int(input())
input()
s=[]
cnt=[0]*101
for n in map(int,input().split()):
    if n in s:
        cnt[n]+=1
    elif len(s) < N:
        s.append(n)
        cnt[n]+=1
    else:
        x=s[0]
        for k in s:
            if cnt[x]>cnt[k]:
                x=k
        s.remove(x)
        cnt[x]=0
        s.append(n)
        cnt[n]+=1
for n in sorted(s): print(n, end=' ')

# N=int(input())
# reco=int(input())
# recos=list(map(int,input().split()))
# comp=[[i,0] for i in range(reco+1)]

# aa=[]

# def goodbye(arr):
#     minimum=1000
#     gg=[]
#     for i in range(len(arr)):
#         if arr[i][1]>0 and arr[i][1] <= minimum:
#             minimum = arr[i][1]
#     for o in range(len(arr)):
#         if arr[o][1]==minimum:
#             gg.append(o)
#     return gg
#
# for i in range(reco):
#     if i <N and recos[i] not in aa:
#         aa.append(recos[i])
#         comp[recos[i]][1] +=1
#         continue
#     if i <N and recos[i] in aa:
#         comp[recos[i]][1] +=1
#         continue
#     if i>=N and recos[i] not in aa:
#         good=goodbye(comp)
#         for h in range(N):
#             if aa[h] in good:
#                 comp[aa[h]][1]=0
#                 aa.pop(h)
#                 break
#         aa.append(recos[i])
#         comp[recos[i]][1] +=1
#         continue
#     if i >=3 and recos[i] in aa:
#         comp[recos[i]][1] +=1
# [print(i, end=' ') for i in sorted(aa)]