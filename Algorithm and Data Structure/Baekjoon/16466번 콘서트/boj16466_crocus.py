n = int(input())
arr = map(int, input().split())
dic = {} # dic = dict()도 됨
 
for i in arr:
    dic[i] = 1
    #dic.update({i: 1})
 
i = 1
while True:
    # 여기서 if not i in dic도 되는데 
    # if i in dic == False는 구조순서상 안된다.(dic == False를 먼저 봄)
    if (i in dic) == False:
        print(i)
        break
    else:
        i += 1
