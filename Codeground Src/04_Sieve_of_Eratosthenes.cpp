#include <stdio.h>
#include <math.h>
#define MAX 1000000
int isPrime[MAX+1];
int prime[MAX+1], cnt, num, testcase, T;

void sieve_Of_Eratosthenes(int N) {
    for (int i = 2; i <= N; i++) {
        isPrime[i] = 1;    // initialize isPrime[] array
    }
    int sqrtn=sqrt(N);
    for (int i = 2; i <= sqrt(N); i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j <= N; j += i) {
            isPrime[j] = 0;
        }
    }
}
int main() {
    sieve_Of_Eratosthenes(MAX);
    scanf("%d", &testcase);
    while (T != testcase) {
        T++;
        scanf("%d", &num);
        printf("Case #%d\n", T);
        if (isPrime[num]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
	