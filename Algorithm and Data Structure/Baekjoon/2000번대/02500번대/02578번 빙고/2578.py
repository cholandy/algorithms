import sys
sys.stdin = open("input.txt", "r")

myboard=[list(map(int, input().split())) for _ in range(5)]
numbers = []
for i in range(5):
    numbers += map(int, input().split())
cnt=0
check=[]
def isBingo(arr):
    global cnt, check
    k=False
    for i in range(5):
        if arr[i][0] !=0:
            continue
        if arr[i][0]==0:
            for j in range(1, 5):
                if arr[i][j]!=0:break
                if j==4:
                    if i==3 and [3,3] not in check:
                        check.append([3,3])
                        cnt += 1
                    elif i==4 and [4,2] not in check:
                        check.append([4,2])
                        cnt += 1
                    elif i==0 and [0,4] not in check:
                        check.append([0,4])
                        cnt += 1
                    elif i==1 and [1,4] not in check:
                        check.append([1,4])
                        cnt += 1
                    elif i==2 and [2,4] not in check:
                        check.append([2,4])
                        cnt += 1
                    k= True
    for j in range(5):
        if arr[0][j]!=0:continue
        if arr[0][j]==0:
            for i in range(1,5):
                if arr[i][j] !=0:break
                if i==4:
                    if j==4 and [3,4] not in check:
                        check.append([3,4])
                        cnt += 1
                    elif j==2 and [3,2] not in check:
                        check.append([3,2])
                        cnt+=1
                    elif j==0 and [3,0] not in check:
                        check.append([3,0])
                        cnt+=1
                    elif j==1 and [4,1] not in check:
                        check.append([4,1])
                        cnt += 1
                    elif j==3 and [4,3] not in check:
                        check.append([4,3])
                        cnt += 1
                    k= True
    for o in range(5):
        if arr[o][o] !=0:
            break
        if o==4 and [o,o] not in check:
            check.append([o,o])
            cnt+=1
            k=True
    for p in range(5):
        if arr[p][4-p] !=0:
            break
        if p==4 and [p,4-p] not in check:
            check.append([p,4-p])
            cnt+=1
            k= True
    if k==True: return True
    return False

for k in range(len(numbers)):
    a=False
    K = False
    for i in range(5):
        for j in range(5):
            if myboard[i][j]==numbers[k]:
                myboard[i][j]=0
                a=True
                break
        if a == True: break
    if isBingo(myboard) == True:
        if cnt>=3:
            print(k+1)
            K=True
            break
    if K==True:
        break
