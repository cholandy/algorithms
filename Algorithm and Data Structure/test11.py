# 문제 1
import collections 
message_num, consumer_num = map(int,input().split())
times_Q = collections.deque()
for i in range(message_num):
    times_Q.append(int(input()))
total =0
cons=[0 for i in range(consumer_num)]

while len(times_Q):
    key = False
    for i in range(len(cons)):
        if cons[i] == 0:
            cons[i] = times_Q.popleft()
        if len(times_Q) == 0:
            key = True
            break
    if key: break
    for i in range(len(cons)):
        cons[i] -= 1
    total +=1

total += max(cons)
print(total)


# 문제 2
import itertools 
a=list(map(int, input().split()))
a.sort()
k = int(input())-1
cnt = 0
for i in itertools.permutations(a):
    if k == cnt:
        print(*i, sep="")
        break
    else:
        cnt +=1
        continue

# 문제 3
n = int(input())
ans = 0
board = [list(0 for _ in range(150)) for _ in range(1000)]
# [print(*i) for i in board]
for i in range(n):
    a ,b = map(int,input().split())
    if sum(board[ans][a:b]) == 0:
        board[ans][a:b] = [1] * (b-a)
    else:
        ans +=1
        board[ans][a:b] = [1]*(b-a)
print(ans+1)

# 문제 4
n = int(input())
space = list(map(int,input().split()))
ans = [0 for _ in range(n)]
getSeat = []
for i in range(n):
    if space[i] == 1:
        getSeat.append(i)
for i in range(n):
    if space[i] == 1:
        continue
    temp = []
    if space[i] == 0:
        for j in range(len(getSeat)):
            anw = abs(getSeat[j] - i)
            temp.append(anw)
        ans[i] = min(temp)
print(max(ans))

# 문제 5
n, m = map(int, input().split())
a, b = map(int, input().split())
mat = [list(0 for _ in range(n)) for i in range(m)]
if a < 0 or a > m or b < 0 or b > n:
    print("fail")
else:
    print(a+b)
    import math
    ans = math.factorial(a+b) / math.factorial(a) / math.factorial(b)
    print(int(ans))

# 문제 6



# 문제 1
import collections 
def solution(record):
    answer = []
    temp = collections.deque()
    for i in record:
        if i in ["SAVE", "DELETE"] and len(answer) and len(temp) == 0:
            continue
        if i == "SAVE" and len(temp):
            while len(temp):
                answer.append(temp.popleft())
        elif i == "DELETE" and len(temp):
            temp.pop()
        else:
            instruct, mail = i.split(" ")
            temp.append(mail)
    return answer

# 문제 2
