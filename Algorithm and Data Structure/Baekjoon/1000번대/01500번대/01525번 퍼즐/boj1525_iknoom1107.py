from collections import deque
g=[[1,3],[0,4,2],[1,5],[0,4,6],[1,3,5,7],[2,4,8],[3,7],[6,4,8],[5,7]]
a=''
for _ in range(3):a+=''.join(input().split())
ans=123456780
vst={int(a):0}
q=deque([a])
while q:
	n=q.popleft();x=n.index('0')
	for k in g[x]:
		t=list(n);t[k],t[x]=t[x],t[k];m=''.join(t)
		if int(m) not in vst:vst[int(m)]=vst[int(n)]+1;q.append(m)				
print(vst[ans] if ans in vst else -1)