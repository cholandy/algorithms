N = int(input())
li = []

for n in range(2700000):
    if '666' in str(n):
        li.append(n)

print(li[N-1])