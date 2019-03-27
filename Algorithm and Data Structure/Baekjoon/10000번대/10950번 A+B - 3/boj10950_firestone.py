import sys
sys.stdin = open('Baekjoon\\10950번 A+B - 3\\input.txt','r')

for _ in range(int(input())):
    a,b=map(int,input().split())
    print(a+b)
