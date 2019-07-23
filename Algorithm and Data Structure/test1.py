from random import randint 
from time import time
print("정렬할 원소의 갯수를 입력하시오: ")
number = int(input())
test_array = [randint(0,10000) for _ in range(number)]



def selectionSort(list):
    idx=0
    for i in range(len(list)):
        min = float('INF')
        for j in range(i,len(list)):
            if min>list[j]: 
                min=list[j]
                idx=j
        list[i],list[idx] = list[idx],list[i]
    return list

def bubbleSort(list):
    for i in range(len(list)):
        for j in range(len(list)-i-1):
            if list[j]>list[j+1]:
                list[j], list[j+1] = list[j+1], list[j]
    return list

def insertionSort(list):
    for i in range(len(list)-1):
        j=i
        while (j>=0 and list[j]>list[j+1]):
            list[j],list[j+1] = list[j+1],list[j]
            j-=1
    return list

def quickSort(list, s,e):
    if (s>=e): return
    key = s
    i,j=s+1,e

    while i<=j:
        while (i<=e and list[i]<=list[key]): i+=1
        while (j>start and list[j]>=list[key]): j-=1
        if i>j:
            list[j],list[key]=list[key],list[j]
        else:
            list[i],list[j]=list[j],list[i]
    quickSort(list,s,j-1)
    quickSort(list,j+1,e)


print(test_array)
start = time()

# selection_sort_return = selectionSort(test_array)
# bubble_sort_return = bubbleSort(test_array)
# insertion_sort_return = insertionSort(test_array)
quick_sort_return = quickSort(test_array,0,number-1)

finish = time()
ret=finish-start


# print(selection_sort_return)
# print(bubble_sort_return)
# print(insertion_sort_return)
print(quick_sort_return)

print(f'정렬에 걸린 시간: {ret}')
print(f"1억번 연산에 {ret/(number**2)}초 약간 넘음")

