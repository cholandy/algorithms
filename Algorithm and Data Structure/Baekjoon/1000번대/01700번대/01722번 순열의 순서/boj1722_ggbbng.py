num_cases = [0 for _ in range(21)]
num_cases[0] = 1
num_cases[1] = 1
for i in range(2, 21):
    num_cases[i] = i*num_cases[i-1]
    

def seq_to_index(seq):
    ans = 0
    N = len(seq)
    left = list(range(1, N + 1))
    for i in range(N - 1):
        index = left.index(seq[i])
        ans += index*num_cases[N - i - 1]
        del left[index]
    return ans + 1


def index_to_seq(N, K):
    seq = []
    left = list(range(1, N + 1))
    for i in range(N):
        index = (K - 1) // num_cases[N - i - 1]
        seq.append(left[index])
        K -= index*num_cases[N - i - 1]
        del left[index]
    return seq


N = int(input())
seq = [int(x) for x in input().split()]
if seq[0] == 1:
    print(*index_to_seq(N, seq[1]))
else:
    print(seq_to_index(seq[1:]))


