#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> x, y;

void solve() {
    int ans = 1e9;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int a = 0, b = 0, c = 0, d = 0;
            for (int k=0; k<n; k++) {
                if (x[k] < x[i]+1 && y[k] < y[j]+1) a++;
                if (x[k] < x[i]+1 && y[k] > y[j]+1) b++;
                if (x[k] > x[i]+1 && y[k] < y[j]+1) c++;
                if (x[k] > x[i]+1 && y[k] > y[j]+1) d++;
            }
            int cow = max(max(max(a, b), c), d);
            if (ans > cow) ans = cow;
        }
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        x.push_back(a);
        y.push_back(b);
    }
    solve();
    return 0;
}


