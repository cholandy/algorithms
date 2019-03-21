from sys import stdin
input = stdin.readline
import heapq

def update(heap):
    while heap and not exist[heap[0][1]]: heapq.heappop(heap)

for TEST in range(int(input())):
    n = int(input())
    minh = []
    maxh = []
    exist = [False]*n
    for i in range(n):
        qtype, val = input().split(); val = int(val)
        if qtype == "I":
            exist[i] = True
            heapq.heappush(minh, (val, i))
            heapq.heappush(maxh, (-val, i))
        elif val == 1:
            update(maxh)
            if not maxh: continue
            v, ind = heapq.heappop(maxh)
            exist[ind] = False
        else:
            update(minh)
            if not minh: continue
            v, ind = heapq.heappop(minh)
            exist[ind] = False
    update(maxh); update(minh)
    if not minh: print("EMPTY")
    else: print(-maxh[0][0], minh[0][0])