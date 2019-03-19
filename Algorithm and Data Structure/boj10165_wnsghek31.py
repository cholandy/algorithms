import sys
station = int(input())
line = int(input())

def order_station(tu) :
    return tu[0]*1000000000 - tu[1]  #이거 10억, 50만개 1.0915446281433105
 
i=0
order_list = []
reverse_list = []
reverse_max=0

while i < line :
    start,end = sys.stdin.readline().split(" ")
    start = int(start)
    end = int(end)
    
    if start < end :
        order_list.append((start,end,i+1))
            
    else :
        order_list.append((start,end+station,i+1))
        reverse_list.append((start,end,i+1))
        if reverse_max < end : 
            reverse_max = end
    i+=1


order_list.sort(key=order_station)

least =0 
i = 0

length = len(order_list)
while i < length:
    if order_list[i][1] > reverse_max :
        break
    i+=1
order_list = order_list[i:length]    
t = len(order_list)   

right = []
# print(order_list)
least=0
i=0
while i < t :
    if least < order_list[i][1] :
        least = order_list[i][1]
        right.append(order_list[i][2])
    i+=1    
right.sort()

for i in right: 
    print(i,end=" ")
