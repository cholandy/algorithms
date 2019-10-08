#include <stdio.h>

#include <algorithm>

using namespace std;

int W[100], V[100]; // 최대 100개의 물품. 
int N, K; // N = 물품의 수, K = 준서가 버틸 수 있는 무게
int dp[101][100001];

int go(int i, int w) {
    if (dp[i][w] > 0) return dp[i][w];
    if (i==N) return 0;
    int n1 = 0;
    if (w + W[i] <= K) {
        n1 = V[i] + go(i + 1, w + W[i]);
    }
    int n2 = go(i + 1, w);
    return dp[i][w] = max(n1, n2);
}

int main(void) {
    scanf("%d %d", & N, & K);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", & W[i], & V[i]);
    }
    printf("%d\n", go(0, 0));
    return 0;
}