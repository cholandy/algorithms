n=int(input())
a=[int(input()) for i in range(n)]
r=0
j=0
for i in range(n):
    if a[i]>j:
        j=a[i]
        r+=1
print(r)
r=0
j=0
for i in range(n):
    if a[n-i-1]>j:
        j=a[n-i-1]
        r+=1
print(r)