input = __import__('sys').stdin.readline
company = set()
for T in range(int(input())):
    entry = input().split()
    if entry[-1] == 'enter':
        company.add(entry[0])
    else:
        company.remove(entry[0])
for p in sorted(company, reverse=True):
    print(p)