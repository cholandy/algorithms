origin_key = {
    '1':[],
    '2':['a','b','c'],
    '3':['d','e','f'],
    '4':['g','h','i'],
    '5':['j','k','l'],
    '6':['m','n','o'],
    '7':['p','q','r','s'],
    '8':['t','u','v'],
    '9':['w','x','y','z'],
}

changed_key = input().split()
target_word = input()
before = None

for c in target_word:
    for k, v in origin_key.items():
        if c in v:
            if before is not None and before == changed_key.index(k)+1:
                print('#', end="")
            # print("test is ", c, v)
            times = v.index(c)+1
            print(str(changed_key.index(k)+1)*times, end="")
            before = changed_key.index(k)+1