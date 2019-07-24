#include <stdio.h>

int d[1001][1001];
char a[1001], b[1001];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int la, lb;
    scanf("%d %d", &la, &lb);
    scanf("%s %s", a + 1, b + 1);

    for(int i = 1; i <= la; i++) {
        d[i][0] = i;
    }
    for(int j = 1; j <= lb; j++) {
        d[0][j] = j;
    }

    for(int i = 1; i <= la; i++) {
        for(int j = 1; j <= lb; j++) {
            if(a[i] == b[j]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = min(min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
            }
        }
    }

    printf("%d\n", d[la][lb]);
    return 0;
}