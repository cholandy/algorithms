import sys
input=sys.stdin.readline
l,m,n=map(int,input().split())
m//=2
a=sorted(list(map(int,input().split())) for x in range(n))
r=1
for i in range(n):
	for j in range(n):
		if 0<a[i][1]-a[j][1]<m:
			t=[]
			for k in range(n):
				if a[i][1]>=a[k][1]>=a[j][1]:
					t.append(a[k][0])
			l=p=0
			for k in t:
				p+=1
				while k-t[l]+a[i][1]-a[j][1]>m:
					p-=1
					l+=1
				r=max(r,p)
print(r)