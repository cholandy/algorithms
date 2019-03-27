from sys import stdin
input = stdin.readline

ids = input().strip()
zone = []
for _ in range(int(input())):
    zone.append(int(input()))
days = (0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)

def leap(y):
    return (y%4 == 0) - (y%100 == 0) + (y%400 == 0)

def solve():
    area = int(ids[0:6])
    if area not in zone:
        print("I")
        return
    year = int(ids[6:10])
    if year < 1900 or year > 2011:
        print("I")
        return
    month = int(ids[10:12])
    if month < 1 or month > 12:
        print("I")
        return
    day = int(ids[12:14])
    if day < 1:
        print("I")
        return
    if leap(year) and month == 2:
        if day > 29:
            print("I")
            return
    else:
        if day > days[month]:
            print("I")
            return
    order = int(ids[14:17])
    if not order:
        print("I")
        return
    x = ids[17:18]
    if x == 'X':
        checksum = 10
    else:
        checksum = int(x)
    for i in range(17):
        checksum += (int(ids[i])*(1<<(17-i)))
        checksum %= 11
    if checksum != 1:
        print("I")
    else:
        if order & 1:
            print("M")
        else:
            print("F")

solve()

