for n in range(int(input())):
    s = input().lower()
    print("Yes" if s[::-1]==s else "No")