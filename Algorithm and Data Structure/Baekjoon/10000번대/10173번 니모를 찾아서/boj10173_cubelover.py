while True:
    s=input()
    if s=='EOI':
        break
    if s.upper().find('NEMO') != -1:
        print('Found')
    else:
        print('Missing')