day=[31,28,31,30,31,30,31,31,30,31,30,31]
eng=['SUN','MON','TUE','WED','THU','FRI','SAT']
m,d = map(int,input().split())
print(eng[(sum(day[:m-1])+d)%7] if m>1 else eng[d%7])


