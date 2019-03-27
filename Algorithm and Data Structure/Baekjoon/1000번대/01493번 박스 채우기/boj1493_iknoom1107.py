L,W,H=map(int,input().split())
N=[0]*20
for _ in range(int(input())):a,b=map(int,input().split());N[a]=b
def f(l,w,h):
	if not l*w*h:return 0
	for i in range(19,-1,-1):
		q=1<<i
		n=(l//q)*(w//q)*(h//q)
		if n:N[i]-=n;return n+f(l%q,w-w%q,h-h%q)+f(l-l%q,w%q,h-h%q)+f(l%q,w%q,h-h%q)+f(l,w,h%q)
ans=f(L,W,H)
for i in range(19,0,-1):
	if N[i]<0:ans-=7*N[i];N[i-1]+=8*N[i]
print(-1 if N[0]<0 else ans)