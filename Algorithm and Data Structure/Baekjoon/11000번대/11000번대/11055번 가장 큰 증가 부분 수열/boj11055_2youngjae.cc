#include <stdio.h>
using namespace std;
 
int n;
int a[1001];
int d[1001];
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
 
    int max = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                if (d[i] < d[j]+a[i]) {
                    d[i] = d[j] + a[i];
                }
            }
            if (d[i] > max) {
                max = d[i];
            }
        }
    }
    printf("%d\n", max);
    
}