stat = [tuple(map(int,input().split())) for i in range(int(input()))]
for i in stat:
    ans = 1
    for j in stat:
        if i[0]<j[0] and i[1]<j[1]:
            ans+= 1
    print(ans,end=' ')