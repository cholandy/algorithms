n=int(input())
a=[list(map(int,input().split())) for i in range(n)]
for i in range(n):
	if a[i]<a[0]:
		a[i],a[0]=a[0],a[i]
d=list(map(lambda t:((t[1]-a[0][1])/(t[0]-a[0][0]) if t[0]!=a[0][0] else 10**10,t),a[1:]))
d.sort()
s=[a[0]]
def f(x,y,z):
	return x[0]*y[1]+y[0]*z[1]+z[0]*x[1]-x[1]*y[0]-y[1]*z[0]-z[1]*x[0]
for i in range(n-1):
	while len(s)>1 and f(s[len(s)-2],s[len(s)-1],d[i][1])<=0:
		s.pop()
	s.append(d[i][1])
print(len(s))