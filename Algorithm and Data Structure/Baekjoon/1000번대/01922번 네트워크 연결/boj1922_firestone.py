import sys;sys.stdin=open('input2.txt','r')
input=__import__('sys').stdin.readline

def make_set(x):
    p[x]=x

def find_set(x):
    if x != p[x]:
        p[x] = find_set(p[x])
    return p[x]

def union(x,y):
    p[find_set(y)]=find_set(x)

def kr():
    a = 0
    for i in range(n+1):
        make_set(i)
    
    for i in inp:
        if find_set(i[0]) != find_set(i[1]):
            a+=i[2]
            union(i[0],i[1])
    return a

def mySort(l,r):
    i,j=0,0
    result=[]
    while i<len(l) and j<len(r):
        if l[i][2]>r[j][2]:
            result.append(r[j])
            j+=1
        else:
            result.append(l[i])
            i+=1
    while i<len(l):
        result.append(l[i])
        i+=1
    while j<len(r):
        result.append(r[j])
        j+=1
    return result

def merge(v):
    if len(v)==1:
        return v
    half=len(v)//2
    l=merge(v[:half])
    r=merge(v[half:])
    return mySort(l,r)

n=int(input())
m=int(input())
inp = [list(map(int,input().split())) for _ in range(m)]
p = [0]*(n+1)
inp = merge(inp)
print(kr())