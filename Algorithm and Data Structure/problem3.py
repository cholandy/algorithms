import sys

sys.stdin = open("problem3_input.txt")

def eat(robot, distance):
    global min_value, N
    if robot == N:
        if distance < min_value:
            min_value = distance
    if distance < min_value:
        for snack in range(N):
            if eatable[snack]:
                eatable[snack] = False
                new_d = distance + abs(snacks[snack*2]-robots[robot*2]) +  abs(snacks[snack*2+1]-robots[robot*2+1])
                eat(robot + 1, new_d)
                eatable[snack] = True


testcase = int(input())

for tc in range(1, testcase + 1):
    N = int(input())
    robots = list(map(int, input().split()))
    snacks = list(map(int, input().split()))
    min_value = 0xfffff
    eatable = [True] * N
    eat(0, 0)
    print("#{} {}".format(tc, min_value))
