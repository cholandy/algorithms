#include <stdio.h>

int coin[100], d[10001];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }

    for(int i = 1; i <= k; i++) {
        d[i] = -1;
        for(int j = 0; j < n; j++) {
            if(coin[j] <= i) {
                if(d[i - coin[j]] < 0) continue;
                if(d[i] < 0) d[i] = d[i - coin[j]] + 1;
                else if(d[i - coin[j]] + 1 < d[i]) d[i] = d[i - coin[j]] + 1;
            }
        }
    }

    printf("%d\n", d[k]);
    return 0;
}