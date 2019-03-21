from math import ceil
n = int(input())
room = map(int,input().split())
b, c = map(int,input().split())

def req(people):
    people = max(0, people-b)
    return ceil(people/c)+1

print(sum(map(req, room)))