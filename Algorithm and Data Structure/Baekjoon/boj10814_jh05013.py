T = int(input())
people = []
for i in range(T):
    a,b=input().split()
    people.append((int(a),i,b))
people.sort()
for p in people:
    print(p[0],p[2])