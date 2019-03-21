n=input()
a=''.join(sorted(n,reverse=True))
if int(a)%30 == 0:
    print(a)
else:
    print(-1)