#include<cstdio>
char pan[101][101];
int main() {
    int N, r, c;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", pan[i]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N - 1; j++)
            r += pan[i][j] == '.' && pan[i][j + 1] == '.' && pan[i][j + 2] != '.',
            c += pan[j][i] == '.' && pan[j + 1][i] == '.' && pan[j + 2][i] != '.';
    printf("%d %d", r, c);
    return 0;
}
