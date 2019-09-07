

s=input()

def one(s):
    string_len = len(s)
    this = ''
    count = 1
    for i in range(string_len):
        if i+1 < string_len:
            if s[i] == s[i+1]:
                count +=1
                if i+1 == string_len -1:
                    this = this + str(count) +s[i] 
            else:
                if count == 1:
                    this = this + s[i]
                else:
                    this = this + str(count) + s[i] 
                    count = 1
        elif i+1 == string_len and count == 1:
            this = this + s[i]
    return len(this)

def solution(s):
    answer = one(s) # 1개 쪼갤 때 값이 들어있음.
    string_len = len(s)

    for _ in range(2, string_len/2+1):
        how_many = _ # 2개씩 쪼개는 것부터 시작. 
        for i in range(0, string_len, how_many):
            count = 1
            this=''
            if i + 2 * how_many < string_len:
                match = s[i:i+how_many]
                next = s[how_many + i : i + 2 * how_many]
                if match == next :
                    count +=1
                    if i + 2 * how_many == string_len - 1:
                        this = this + str(count) + match
                        break
            elif i + 2 * how_many == string_len and count == 1: 
                pass

    
    return answer