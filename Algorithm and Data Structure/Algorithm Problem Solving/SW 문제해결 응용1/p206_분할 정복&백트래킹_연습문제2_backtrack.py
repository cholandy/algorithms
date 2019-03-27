arr=[1,2,3,4,5,6,7,8,9,10]
chk=[0 for i in range(10)]
def backtrack(ary, k, n, sum):
    if sum>10: return
    if k==n:
        if sum==10:
            for j in range(n):
                if chk[j]:print(ary[j],end=" ")
            print()
        return
    k+=1
    chk[k-1]=1
    backtrack(ary,k,n,sum+ary[k-1])
    chk[k-1]=0
    backtrack(ary,k,n,sum)
backtrack(arr,0,10,0)