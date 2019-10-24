#include <stdio.h>

#define N 50

int memo[N]={0};

int fibonacci(int n) {
    if (memo[n] != 0) {
        return memo[n];
    }
    if (n==1 || n==2) {
        memo[n] = 1;
    } else {
        memo[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return memo[n];
}

int main() {
    int n, ans;
    scanf("%d", &n);
    ans = fibonacci(n);
    printf("%d\n", ans);
    return 0;
}