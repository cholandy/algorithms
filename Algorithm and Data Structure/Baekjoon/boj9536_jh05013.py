for t in range(int(input())):
    sound = input().split()
    other = []
    while 1:
        s = input()
        if 'goes' in s:
            other.append(s.split(' goes ')[1])
        else:
            break
    for i in range(len(sound)):
        c = sound[i]
        if c in other:
            sound[i] = ''
    print(' '.join(list(filter(None,sound))))