import sys

def init(x):
    return list(map(int,x.split()))

n, m = list(map(int,input().split()))
s = sys.stdin.readlines()
sports = list(map(int, s[:n]))
members = list(map(int,s[n:]))
vote = [0]*n

for i in range(m):
    for j in range(n):
        if(sports[j] <= members[i]):
            vote[j] += 1
            break
vmax = max(vote)
for i in range(m):
    if(vote[i] == vmax):
        print(i+1)
        break
