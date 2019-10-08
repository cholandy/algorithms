import sys;sys.stdin=open('Baekjoon\\11720번 숫자의 합\\input.txt', 'r')
n=int(input())
num=input().rstrip()
ret=0
for i in range(n):
    ret+=int(num[i])
print(ret)