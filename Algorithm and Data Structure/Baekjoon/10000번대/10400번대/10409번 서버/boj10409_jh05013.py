n,T = map(int,input().split())
work = list(map(int,input().split()))+[5000]
tot = 0
i = 0
while tot <= T:
    tot+= work[i]
    i+= 1
print(i-1)