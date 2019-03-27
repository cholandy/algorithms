#include <cstdio>
#include <algorithm>
using namespace std;

int a[6], b[6];

inline int one(int i, int j, int k) {
    return (a[i]+a[j]+a[k])*max({b[i],b[j],b[k]});
}

inline int two(int i, int j, int k) {
    return max(a[i]+a[j],a[k])*(max(b[i],b[j])+b[k]);
}

int go() {
    int ret = 1e9;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                if (i%3==j%3 || j%3==k%3 || k%3==i%3) {
                    continue;
                }
                ret = min(ret, one(i,j,k));
                ret = min(ret, two(i,j,k));
            }
        }
    }
    return ret;
}

int main() {
    int tc;
    for (scanf("%d", &tc); tc--;) {
        for (int i = 0; i < 3; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            a[i] = b[i+3] = x;
            b[i] = a[i+3] = y;
        }

        printf("%d\n", go());
    }

    return 0;
}