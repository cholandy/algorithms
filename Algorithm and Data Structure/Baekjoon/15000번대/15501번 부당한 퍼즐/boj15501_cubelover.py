from heapq import heapify, heappush, heappop
import sys
input = sys.stdin.readline

input()
a = list(map(int, input().split()))
b = list(map(int, input().split()))
i = a.index(1)
a = a[i+1:]+a[:i]
i = b.index(1)
b = b[i+1:]+b[:i]
print('good puzzle' if a == b or a == b[::-1] else 'bad puzzle')
