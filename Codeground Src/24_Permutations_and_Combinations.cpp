#include <stdio.h>

int comb[1001][1001];

void calc_combination() {
    comb[0][0] = 1;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
                comb[i][j] = 1;
            } else {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 1000007;
            }
        }
    }
}

int main() {
    calc_combination();

    int q;
    scanf("%d", &q);

    while(q--) {
        int n, r;
        scanf("%d %d", &n, &r);
        printf("%d\n", comb[n][r]);
    }
    return 0;
}