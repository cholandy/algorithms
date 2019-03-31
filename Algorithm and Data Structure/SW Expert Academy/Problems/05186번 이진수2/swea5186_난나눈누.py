import sys;sys.stdin=open('input1.txt','r')
# input=__import__('sys').stdin.readline
def decimal_to_r_notations(number,r):
    number_front=int(number)
    number_rear=number-number_front
    remainder_list=[]
    while 1:
        quotient,remainder=divmod(number_front,r)
        # remainder=divmod(number_front,r)
        remainder_list.append(remainder)
        if quotient==0:break
        else:
            number_front=quotient
    remainder_list.reverse()
    result_front=''
    for digit in remainder_list:
        result_front+=str(digit)
    integer_part_list=[]
    cnt=0
    while 1:
        if cnt==13:return "overflow"
        integer_part=int(number_rear*r)
        decimal_part=number_rear*r-integer_part
        integer_part_list.append(integer_part)
        cnt+=1
        if decimal_part==0:break
        else:
            number_rear=decimal_part

    result_rear=''
    for digit in integer_part_list:
        result_rear+=str(digit)
    result=result_front +'.' +result_rear
    return result[2:]

for tc in range(int(input())):
    a=input()
    print(f'#{tc+1} {decimal_to_r_notations(float(a),2)}')
    # b=bin(a)
    # print(b)


    # print(f'#{tc+1} {ans}')