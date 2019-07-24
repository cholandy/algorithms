#include <stdio.h>

int lcs[1001][1001];
char a[1001], b[1001];

int main() {
    int la, lb;
    scanf("%d %d", &la, &lb);
    scanf("%s %s", a + 1, b + 1);

    for(int i = 1; i <= la; i++) {
        for(int j = 1; j <= lb; j++) {
            if(a[i] == b[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                if(lcs[i - 1][j] < lcs[i][j - 1]) {
                    lcs[i][j] = lcs[i][j - 1];
                } else {
                    lcs[i][j] = lcs[i - 1][j];
                }
            }
        }
    }

    printf("%d\n", lcs[la][lb]);
    return 0;
}