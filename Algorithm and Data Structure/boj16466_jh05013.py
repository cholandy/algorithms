n = int(input())
tic = set(map(int,input().split()))
for i in range(1, n+2):
    if i not in tic: print(i); exit()