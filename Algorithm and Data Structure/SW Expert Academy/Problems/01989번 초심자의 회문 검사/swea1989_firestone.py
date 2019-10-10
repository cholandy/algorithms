for _ in range(int(input())):
    word = input()
    reword = word[::-1]
    if word == reword:
        print('#{} 1'.format(_+1))
    else:
        print('#{} 0'.format(_+1))
