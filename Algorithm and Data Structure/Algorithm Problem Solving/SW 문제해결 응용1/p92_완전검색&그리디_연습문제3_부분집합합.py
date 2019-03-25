arr = [-1,3,-9,6,7,-6,1,5,4,-2]
n=len(arr)
for i in range(0, (1<<n)):
    temp=[]
    tol=0
    for j in range(0,n):    
        if i&(1<<j):
            temp.append(arr[j])
    for i in range(len(temp)):
        tol+=temp[i]
    if tol==0 and temp != []:
        print(temp)