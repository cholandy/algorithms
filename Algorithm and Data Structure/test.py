# from collections import deque
import sys;sys.stdin=open('input.txt','r')
coin = [6,4,1]
solution=[0]*1000
MIN=0xfffff
def coinChange(k,n): # k는 지금까지 고른 동전 갯수, n은 잔액
    global MIN
    if k >=MIN:return # 가지치기
    if n==0: 
        MIN = min(MIN,k)
        print(solution[:k])
        return
    for value in coin:
        if value>n:continue
        solution[k]=value
        coinChange(k+1, n-value)

coinChange(0,800)

