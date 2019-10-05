#include <bits/stdc++.h>

#define NN 300010

using namespace std;

struct data {
    int pos, val;
} X[NN], Y[NN];
int N, M, a, b;
long long sum[NN], ans;

void input(int &n, data arr[]) {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%d %d", &arr[i].pos, &arr[i].val);
    }
}

int main() {
    int s = 0, e = 0;
    input(N, X);
    input(M, Y);
    scanf("%d %d", &a, &b);
    for (int i=1; i<=M; i++) {
        sum[i] += sum[i-1] + Y[i].val;
    }
    for (int i=1; i<=N; ++i) {
        while (e < M && Y[e+1].pos <= X[i].pos + b) e++;
        while (s < M && Y[s+1].pos < X[i].pos + a) s++;
        ans += X[i].val * (sum[e] - sum[s]);
    }

    printf("%lld\n", ans);
    return 0;
}