#include <stdio.h>
using namespace std;
 
int n, m;
long long tree[1000000];
 
bool chk(int mid) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (mid < tree[i])
            sum += tree[i] - mid;
    }
 
    return sum >= m;
}
 
int main() {
    scanf("%d %d", &n, &m);
 
    int max = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &tree[i]);
        if (tree[i] > max)
            max = tree[i];
    }
 
 
    int left = 0, right = max;
    int ans = 0;
 
    while (left <= right) {
        int mid = (left + right) / 2;
 
        if (chk(mid)) {
            if (ans < mid)
                ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
 
    printf("%d", ans);
 
    return 0;
}