#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

pair<int, int> a[5005];
int L[5005], R[5005];

int f(const pair<int, int> &u, const pair<int, int> &v) {
    int dx = u.first - v.first, dy = u.second - v.second;
    return dx * dx + dy * dy;
}

bool g(const pair<int, int> &u, const pair<int, int> &v) {
    return f(a[0], u) < f(a[0], v);
}

int main() {
    double T, M  = 1e9;
    int i, j, k, n, m, r = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
        for (j = 0; j < i; j++) {
            k = f(a[i], a[j]);
            if (k > r) {
                r = k;
                m = i;
            }
        }
    }
    swap(a[0], a[m]);
    sort(a + 1, a + n, g);
    for (i = 1; i < n; i++) for (j = 0; j < i; j++) {
        k = f(a[i], a[j]);
        if (k > L[i]) L[i] = k;
        if (k > R[j]) R[j] = k;
    }
    for (i = 1; i < n; i++) {
        if (L[i] < L[i - 1]) L[i] = L[i - 1];
        if (R[n - i - 1] < R[n - i]) R[n - i - 1] = R[n - i];
    }
    for (i = 1; i < n; i++) {
        T = sqrt(L[i - 1]) + sqrt(R[i]);
        if (T < M) M = T;
    }
    printf("%f", M);
}