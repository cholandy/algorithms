import sys; sys.stdin = open("input.txt", "r");
N = int(input())
simulation_data = [list(map(int, input().split())) for _ in range(4)]

def rebal(timezone, sum_time, N):
    for i in range(N):
        if timezone[i] == min(timezone):
            timezone[i] = sum_time
            break
    timezone.sort()

def solution(N, simulation_data):
    timezone = [0] * N
    total_waiting = 0
    client_number = len(simulation_data)
    for i in range(N):
        timezone[i] = sum(simulation_data[i])

    for i in range(N, client_number):
        wait_num_get_time, counsel_time = simulation_data[i]
        sum_time = wait_num_get_time + counsel_time

        if wait_num_get_time < min(timezone):
            total_waiting += min(timezone) - wait_num_get_time
            sum_time = min(timezone) + counsel_time
            rebal(timezone, sum_time,N)
            continue

        for j in range(N):
            if timezone[j] >= wait_num_get_time:
                timezone[j] = sum_time
                break
            elif timezone[j] < wait_num_get_time:
                timezone[j] = sum_time
                timezone.sort()
                break

    return total_waiting



print(solution(N, simulation_data))