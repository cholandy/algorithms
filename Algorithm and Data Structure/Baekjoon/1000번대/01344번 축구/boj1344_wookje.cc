#include <cstdio>

int p[12] = { 0,1,4,6,8,9,10,12,14,15,16,18 };
double a, b, d[19][19][19];

int main() {
    scanf("%lf %lf", &a, &b);

    a /= 100, b /= 100;
    d[0][0][0] = 1;
    for (int t = 0; t <= 17; t++) {
        for (int x = 0; x <= t; x++) {
            for (int y = 0; y <= t; y++) {
                double now = d[t][x][y];
                d[t+1][x][y] += now*(1-a)*(1-b);
                d[t+1][x+1][y] += now*a*(1-b);
                d[t+1][x][y+1] += now*(1-a)*b;
                d[t+1][x+1][y+1] += now*a*b;
            }
        }
    }

    double ans = 1;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            ans -= d[18][p[i]][p[j]];
        }
    }

    printf("%.15lf\n", ans);

    return 0;
}