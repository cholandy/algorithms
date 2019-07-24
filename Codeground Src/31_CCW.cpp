#include <stdio.h>
int T;
typedef struct point {
    int x, y;
} dot;
dot A, B, C;

int ccw(dot a, dot b, dot c) {
    dot ab;
    ab.x = b.x - a.x;
    ab.y = b.y - a.y;
    dot bc;
    bc.x = c.x - b.x;
    bc.y = c.y - b.y;
    int ret = ab.x*bc.y - ab.y*bc.x;
    if (ret > 0) return 1;
    else if (ret == 0) return 0;
    else return -1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d",&A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
        int result = ccw(A, B, C);
        printf("%d\n", result);
    }
}