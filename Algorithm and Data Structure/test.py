from itertools import permutations as pm, combinations as cb

arr=[3,6,7,1,5,4]
arr.sort()
n=len(arr)
for i in range(1<<n): #0부터 63까지
    aa=str(bin(i&63))[2:].count('1')
    if aa==4:
        for j in range(n+1):
            if i&(1<<j):
                print(arr[j], end=' ')
        print()
print()
for i in cb(arr,4):
    print(*i)
