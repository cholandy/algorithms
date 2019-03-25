# 일반적인 selection sort

def selectionSort(A):
    n=len(A)
    for i in range(0,n-1):
        min=i
        for j in range(i+1,n):
            if A[j] < A[min]:
                min = j
        A[i], A[min] = A[min], A[i]

# 재귀를 사용한 selecetion sort
# 동영이 코드
def recursiveSelectionSort(arr):
    if len(arr)==1: return arr
    else:
        minIdx=arr.index(min(arr))
        return [arr.pop(minIdx)]+recursiveSelectionSort(arr)

# 선생님 코드
def recursiveSelectionSort2(n):
    if n==(len(inp)-1): return
    minVal = inp[n]
    for i in range(n+1, len(inp)):
        if inp[i]<minVal:
            minVal=inp[i]
            mIdx=i
    inp[n], inp[mIdx] = inp[mIdx], inp[n]
    return
inp = list(map(int,input().split()))
recursiveSelectionSort2(0)
print(inp)
