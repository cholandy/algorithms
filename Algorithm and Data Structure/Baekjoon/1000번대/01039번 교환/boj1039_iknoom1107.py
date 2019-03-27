N,K=input().split()
q=[N]
for _ in range(int(K)):
	vst=set();p=[]
	for n in q:
		for i in range(len(n)-1):
			for j in range(i+1,len(n)):
				if i or n[j]!='0':
					t=[*n];t[i],t[j]=t[j],t[i];m=''.join(t)
					if m not in vst:vst.add(m);p.append(m)
	q=p[:]
print(max(vst) if vst else -1)