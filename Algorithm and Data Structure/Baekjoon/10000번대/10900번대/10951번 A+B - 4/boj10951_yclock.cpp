#include <stdio.h>

int A, B;

int main() {
    for(; ~scanf("%d%d", &A, &B); printf("%d\n", A+B));
    return 0;
}