#include <bits/stdc++.h>
using namespace std;

struct data {
    long long x, y, xgrow, ygrow;
    bool operator< (const data &r) const {
        return ygrow * r.xgrow - r.ygrow * xgrow < 0;
    }
} dot[3010];
int N, D[3010][2], P[3010][2];

int ccw(data s, data a, data b) {
    double tmp = (a.y - s.y) * (b.x - s.x) - (b.y - s.y) * (a.x - s.x);
    if (tmp > 0) return 0;
    if (tmp < 0) return 1;
    return -1;
}

bool same(data a, data b) {
    return a.xgrow * b.ygrow == a.ygrow * b.xgrow;
}

void input() {
    int i;
    scanf("%d", &N);
    for (i=0; i<N; ++i) {
        scanf("%lld %lld", &dot[i].x, &dot[i].y);
        if (dot[i].y < dot[0].y) swap(dot[0], dot[i]);
    }
    for (i=1; i<N; ++i) {
        D[i][1] = 1;
        dot[i].xgrow = dot[i].x - dot[0].x;
        dot[i].ygrow = dot[i].y - dot[0].y;
    }
    sort(dot+1, dot+N);
}

void dy() {
    int i,j,k;
    for (i=2; i<N; ++i) {
        for (j=1; j<i; ++j) {
            if (same(dot[i], dot[j])) continue;
            for (k=0; k<2; ++k) {
                if (ccw(dot[P[j][1-k]], dot[i], dot[j]) != k) continue;
                if (D[i][k] > D[j][1-k]+1) continue;
                if (D[i][k] < D[j][1-k]+1) {
                    D[i][k] = D[j][1-k]+1, P[i][k]=j;
                } else if (ccw(dot[i], dot[j], dot[P[i][k]]) == k) P[i][k] = j;
            }
        }
    }
}

void prn(int k, int p) {
    if (k) prn(P[k][p], 1-p);
    printf("%lld %lld\n", dot[k].x, dot[k].y);
}

int main() {
    input();
    dy();
    int i, k=0;
    for (i=1; i<N; ++i) if (D[k][1] < D[i][1]) k = i;
    if (D[k][1] < 3) printf("0\n");
    else {
        printf("%d\n", D[k][1]+1);
        prn(k,1);
    }
    return 0;
}