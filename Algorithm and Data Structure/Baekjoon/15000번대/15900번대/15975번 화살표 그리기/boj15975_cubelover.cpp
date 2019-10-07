#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> a[100001];
 
int main() {
    long long r = 0;
    int i, j, k, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &j, &k);
        a[k].push_back(j);
    }
    for (i = 1; i <= n; i++) if (a[i].size() > 1) {
        sort(a[i].begin(), a[i].end());
        r += a[i][1] - a[i][0] + a[i][a[i].size() - 1] - a[i][a[i].size() - 2];
        for (j = 1; j + 1 < a[i].size(); j++) {
            r += min(a[i][j] - a[i][j - 1], a[i][j + 1] - a[i][j]);
        }
    }
    printf("%lld\n", r);
    return 0;
}