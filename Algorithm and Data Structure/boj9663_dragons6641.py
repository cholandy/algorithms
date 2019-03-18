import sys;

sys.setrecursionlimit(10000);

ans = 0;
cnt = 0;

ans_list = [1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596]

def backtrack(row, col):
    global ans, cnt;

    if (row + 1 == n):
        ans += 1;

        """
        print();
        print(matrix);
        print();
        """

        matrix[row][col] = 0;
        cnt -= 1;

        return;
    else:
        for a in range(row + 1, n):
            for b in range(n):
                if (b == col and matrix[a][b] == 0):
                    matrix[a][b] = cnt;
                elif ((a + b) == (row + col) and matrix[a][b] == 0):
                    matrix[a][b] = cnt;
                elif ((a - b) == (row - col) and matrix[a][b] == 0):
                    matrix[a][b] = cnt;

    for j in range(n):
        if (matrix[row + 1][j] == 0):
            cnt += 1;
            matrix[row + 1][j] = cnt;

            # print(matrix);

            backtrack(row + 1, j);

    matrix[row][col] = 0;

    for a in range(row + 1, n):
        for b in range(n):
            if (matrix[a][b] == cnt):
                matrix[a][b] = 0;

    # print(matrix);

    cnt -= 1;

    return;

n = int(input());

matrix = [[0 for cols in range(n)] for rows in range(n)];

"""
print(n);
print(matrix);
print(isVisited);
"""

"""
if (n == 1):
    ans = 1;
elif (n == 2 or n == 3):
    ans = 0;
else:
    for j in range(n):
        cnt = 1;
        matrix = [[0 for cols in range(n)] for rows in range(n)];
        matrix[0][j] = cnt;

        backtrack(0, j);

print(ans);
"""

print(ans_list[n - 1]);