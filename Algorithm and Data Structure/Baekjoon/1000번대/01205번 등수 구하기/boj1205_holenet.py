import sys
sys.setrecursionlimit(100000000)
# def input(): return sys.stdin.readline()[:-1]
def iin(): return int(input())
def impin(): return map(int, input().split())
def irrin(): return [int(x) for x in input().split()]
def imrin(n): return [int(input()) for _ in range(n)]


# entire input
def entire_input():
    entire = []
    try:
        while True:
            entire += input().split()
    except Exception as e:
        pass
    return entire


entire = entire_input()
n, x, p = map(int, entire[:3])
arr = [int(x) for x in entire[3:]]
for i in range(len(arr)):
    if x>arr[i]:
        arr.insert(i, x)
        s = i
        break
else:
    arr.append(x)
    s = n
if p<=s:
    print(-1)
else:
    cnt = 0
    for i in range(s):
        cnt += arr[i]>x
    print(cnt+1)
