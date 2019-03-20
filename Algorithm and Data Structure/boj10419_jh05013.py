late = [0]*10001
d = 1
t = 2
for i in range(10001):
    if t > i:
        late[i] = late[i-1]
    else:
        late[i] = late[i-1]+1
        d+= 1
        t = d**2+d
for i in range(int(input())):
    print(late[int(input())])