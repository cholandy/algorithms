import sys
input = sys.stdin.readline
a = min(map(int, input().split()))
x = sorted(map(int, input().split()))
y = sorted(map(int, input().split()))
z = sorted(map(int, input().split()))
s = sum(x) + sum(y) + sum(z)
print(s)
s -= (sum(x[-a:]) + sum(y[-a:]) + sum(z[-a:])) // 10
print(s)