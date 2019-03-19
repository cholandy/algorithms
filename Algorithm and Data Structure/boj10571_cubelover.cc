#include <cstdio>
#include <algorithm>

using namespace std;

pair<double, double> a[202];
int d[202];

int main() {
    int tcn;
    scanf("%d", &tcn);
    while (tcn--) {
        int i, j, n, r = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%lf%lf", &a[i].first, &a[i].second);
        for (i = 0; i < n; i++) {
            d[i] = 0;
            for (j = 0; j < i; j++) if (d[j] > d[i] && a[j].first < a[i].first && a[j].second > a[i].second) d[i] = d[j];
            d[i]++;
            if (d[i] > r) r = d[i];
        }
        printf("%d\n", r);
    }
}