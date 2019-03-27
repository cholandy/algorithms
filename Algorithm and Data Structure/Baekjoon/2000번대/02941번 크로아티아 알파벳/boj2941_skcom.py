t = input()
s = len(t)

for i in range(len(t)-1):
    if(t[i] == 'c' and (t[i+1] == '=' or t[i+1] == '-')):
        s -= 1
    if(t[i] == 'd' and t[i+1] == '-'):
        s -= 1
    if(t[i] == 'l' and t[i+1] == 'j'):
        s -= 1
    if(t[i] == 'n' and t[i+1] == 'j'):
        s -= 1
    if(t[i] == 's' and t[i+1] == '='):
        s -= 1
    if(t[i] == 'z' and t[i+1] == '='):
        s -= 1

for i in range(len(t)-2):
    if(t[i] == 'd' and t[i+1] == 'z' and t[i+2] == '='):
        s -= 1

print(s)
