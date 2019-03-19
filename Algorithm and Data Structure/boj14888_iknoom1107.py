M=-10**9
m=10**9
N=int(input())
num=list(map(int,input().split()))
a,b,c,d=map(int,input().split())
def inst(n,i,d1,d2,d3,d4):
	global M,m
	if i==N:M=max(M,n);m=min(m,n);return 
	else:
		if d1:inst(n+num[i],i+1,d1-1,d2,d3,d4)
		if d2:inst(n-num[i],i+1,d1,d2-1,d3,d4)
		if d3:inst(n*num[i],i+1,d1,d2,d3-1,d4)
		if d4:inst(int(n/num[i]),i+1,d1,d2,d3,d4-1)
inst(num[0],1,a,b,c,d)
print(M)
print(m)