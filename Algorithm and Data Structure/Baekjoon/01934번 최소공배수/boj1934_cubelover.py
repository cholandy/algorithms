import fractions
for i in range(int(input())):
    a, b = map(int, input().split())
    print(a * b // fractions.gcd(a, b))