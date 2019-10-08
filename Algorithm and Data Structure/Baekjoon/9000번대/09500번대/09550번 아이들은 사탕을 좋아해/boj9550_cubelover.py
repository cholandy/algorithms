import sys
input=sys.stdin.readline
for tc in range(int(input())):
	n,m=map(int,input().split())
	print(sum(map(lambda x:int(x)//m,input().split())))