arr = ['','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
c_arr = []
x = input().split()
string = input()

for item in x:
    c_arr.append(arr[int(item)-1])
sentence = []
for s in string:
    for i in range(len(c_arr)):
        for j, item in enumerate(c_arr[i]):
            if(item == s):
                sentence.append(str(i+1)*(j+1))

for i in range(len(sentence)-1):
    if(sentence[i][-1] == sentence[i+1][0]):
        sentence[i] += '#'

print(''.join(sentence))