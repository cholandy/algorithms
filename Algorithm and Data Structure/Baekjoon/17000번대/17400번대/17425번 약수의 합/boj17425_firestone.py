import sys
tc = int(input())
MAX = 1000000
arr = [0] * (MAX+1)
for i in range(1, MAX+1):
    for j in range(1, (MAX//i)+1):
        arr[i*j] += j
    arr[i] += arr[i-1]
for _ in range(tc):
    n = int(sys.stdin.readline())
    sys.stdout.write(str(arr[n])+"\n")
