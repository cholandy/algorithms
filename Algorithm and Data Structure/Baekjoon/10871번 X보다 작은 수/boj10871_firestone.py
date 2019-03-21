input=__import__('sys').stdin.readline
n,x=map(int,input().split())
[print(i, end=' ') for i in list(map(int,input().split())) if i<x]