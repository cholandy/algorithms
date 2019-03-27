import sys;sys.stdin=open('Baekjoon\\11721번 열 개씩 끊어 출력하기\\input.txt','r')
w=input()
for i in range(0,len(w),10):
    if i+10<=len(w):print(w[i:i+10])
    elif i+10>len(w):print(w[i:])