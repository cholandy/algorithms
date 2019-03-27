input()
ind = list(map(int,input().split()))
a = []
for i in range(len(ind)):
    a.insert(ind[i],str(i+1))
print(' '.join(a[::-1]))