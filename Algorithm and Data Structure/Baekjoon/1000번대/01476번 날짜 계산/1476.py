import sys
sys.stdin = open('input.txt', 'r')

a,b,c=map(int, input().split())
a,b,c=a%15,b%28,c%19
year=0

while True:
    q, w, e = year % 15, year % 28, year % 19
    # a가 0일 때
    if a==0 and b!=0 and c!=0:
        year +=15
        if a==q and b==w and c==e:
            print(year-15)
            break
        continue
    # b가 0일 때
    elif a!=0 and b==0 and c!=0:
        year+=28
        if a==q and b==w and c==e:
            print(year-28)
            break
        continue
    # e가 0일 때
    elif a!=0 and b!=0 and c==0:
        year+=19
        if a==q and b==w and c==e:
            print(year-19)
            break
        continue
    # a,b가 0일 때
    elif a==0 and b==0 and c!=0:
        year+=420
        if a==q and b==w and c==e:
            print(year-420)
            break
        continue
    # a,e가 0일 때
    elif a==0 and b!=0 and e==0:
        year+=285
        if a==q and b==w and c==e:
            print(year-285)
            break
        continue
    # b,e가 0일 때
    elif a!=0 and b==0 and e==0:
        year+=532
        if a==q and b==w and c==e:
            print(year-532)
            break
        continue
    # a,b,e가 0일 때
    elif a==0 and b==0 and c==0:
        year+=7980
        print(year)
        break
    else:
        year+=1
        if a==q and b==w and c==e:
            print(year-1)
            break

