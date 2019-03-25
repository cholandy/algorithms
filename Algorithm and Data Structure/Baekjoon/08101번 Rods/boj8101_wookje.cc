#include <cstdio>
#include <cmath>
int tc;
double L, LD, R, l, r, th;
int main() {
    for (scanf("%d", &tc); tc--;) {
        scanf("%lf %lf", &L, &LD);
        LD += L, l = 0, r = 3.142;
        for (int i = 0; i < 50; i++) {
            th = (l+r)/2;
            (sin(th)/th<L/LD ? r : l) = th;
        }
        r = LD/2/th;
        printf("%.0lf\n", r*(1-cos(th)));
    }
    return 0;
}