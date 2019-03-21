import sys
from collections import deque
q=int(sys.stdin.readline())
dq=deque()
for i in range(q):
	a=sys.stdin.readline().rstrip()
	if a[:10]=='push_front':
		dq.appendleft(int(a[11:]))
	if a[:9]=='push_back':
		dq.append(int(a[10:]))
	if a=='pop_front':
		if len(dq)==0:print(-1)
		else:
			print(dq.popleft())
	if a=='pop_back':
		if len(dq)==0:print(-1)
		else:
			print(dq.pop())
	if a=='size':
		print(len(dq))
	if a=='empty':
		if len(dq)==0:
			print(1)
		else:print(0)
	if a=='back':
		if len(dq)==0:print(-1)
		else:print(dq[-1])
	if a=='front':
		if len(dq)==0:print(-1)
		else:print(dq[0])