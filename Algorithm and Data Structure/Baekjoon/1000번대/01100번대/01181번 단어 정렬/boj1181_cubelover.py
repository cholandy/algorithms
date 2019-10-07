import sys
for x in sorted(list(map(lambda t: (len(t), t), set(sys.stdin.readline() for _ in range(int(sys.stdin.readline())))))):
    print(x[1][:-1])