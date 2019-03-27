#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int n_ = 1001;

int n, w, x[n_+2], y[n_+2], dp[n_][n_], t1[n_][n_], t2[n_][n_];

inline int dst(int a, int b, int t) {
    if (!a) {
        a = t ? 1002 : 1001;
    }
    return abs(x[b]-x[a]) + abs(y[b]-y[a]);
}

inline void calc(int a, int b, int c, int d, int e, int f, int g) {
    if (dp[a][b] > dp[c][d]+dst(e,f,g)) {
        dp[a][b] = dp[c][d]+dst(e,f,g);
        t1[a][b] = g;
        t2[a][b] = g ? d : c;
    }
}

void trace(int i, int j) {
    if (!i && !j) {
        return;
    }
    if (!t1[i][j]) {
        trace(t2[i][j], j);
    }
    else {
        trace(i, t2[i][j]);
    }
    printf("%d\n", t1[i][j]+1);
}

void input() {
    scanf("%d %d", &n, &w);
    for (int i = 1; i <= w; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    memset(dp, 0x3f, sizeof(dp));
    x[1001] = y[1001] = 1; dp[1][0] = dst(0,1,0);
    x[1002] = y[1002] = n; dp[0][1] = dst(0,1,1);
    t1[1][0] = 0; t1[0][1] = 1;
}

void process() {
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == j) {
                continue;
            }
            else if (i && i == j-1) {
                for (int k = 0; k <= j-2; k++) {
                    calc(i,j,i,k,k,j,1);
                }
            }
            else if (j && j == i-1) {
                for (int k = 0; k <= i-2; k++) {
                    calc(i,j,k,j,k,i,0);
                }
            }
            else if (i < j) {
                calc(i,j,i,j-1,j-1,j,1);
            }
            else {
                calc(i,j,i-1,j,i-1,i,0);
            }
        }
    }
}

void output() {
    int ans = 2e9, flag, pos;
    for (int i = 0; i < w; i++) {
        if (ans > dp[i][w]) {
            ans = dp[i][w];
            pos = i;
            flag = 1;
        }
        if (ans > dp[w][i]) {
            ans = dp[w][i];
            pos = i;
            flag = 0;
        }
    }

    printf("%d\n", ans);
    if (flag) {
        trace(pos, w);
    }
    else {
        trace(w, pos);
    }
}

int main() {
    input();
    process();
    output();

    return 0;
}