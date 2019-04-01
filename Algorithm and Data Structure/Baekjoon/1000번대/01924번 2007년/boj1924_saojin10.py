m=[0,0,3,3,6,1,4,6,2,5,0,3,5]
t=['SUN','MON','TUE','WED','THU','FRI','SAT']
a,b=map(int,input().split())
print(t[(b+m[a])%7])