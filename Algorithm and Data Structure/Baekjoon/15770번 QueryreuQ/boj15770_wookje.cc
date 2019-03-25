#include <cstdio>

int q, len, dp[10003];
char c, str[10003];
bool chk[10003][10003];

int main() {
    scanf("%d ", &q);
    while (q--) {
        scanf("%c", &c);

        if (c == '-') {
            dp[len] = 0;
            for (int i = 1; i < len; i++) {
                chk[i][len-i] = chk[len][i] = 0;
            }
            printf("%d ", dp[--len]);
            continue;
        }

        str[++len] = c;
        dp[len] = dp[len-1] + 1;
        chk[len][0] = 1;
        if (str[len-1] == c) {
            dp[len]++;
            chk[len-1][1] = 1;
        }
        for (int i = 2; i < len; i++) {
            if (!chk[i][len-i-1] || str[i-1] != c) {
                continue;
            }
            dp[len]++;
            chk[i-1][len-i+1] = 1;
        }

        printf("%d ", dp[len]);
    }

    return 0;
}