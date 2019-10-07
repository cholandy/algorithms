n=int(input())
s=int((n+n)**.5+.5)
if s%2==0:
    print("%d/%d"%(n-s*(s-1)//2,s*(s+1)//2-n+1))
else:
    print("%d/%d"%(s*(s+1)//2-n+1,n-s*(s-1)//2))