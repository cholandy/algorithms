#include <cstdio>
#include <algorithm>
using namespace std;
char a[110];
int k, p[2000000];
bool chk(const char *s, int p) {
    int ret = 0;
    for (int i = 0; s[i]; i++)
        ret = (ret * 10 + s[i] - '0') % p;
    return !ret ? true : false;
}
int main() {
    scanf("%s%d", &a, &k);
    for (int i = 2; i < 2000000; i++) {
        if (p[i])continue;
        for (int j = i + i; j < 2000000; j += i)
            p[j] = true;
    }
    int r = 0, pp = 987654321;
    for (int i = 2; i <= k; i++) {
        if (p[i])continue;
        if (chk(a, i)) {
            r = 1;
            pp = min(pp, i);
        }
    }
    printf("%s ", r ?  "BAD" : "GOOD");
    if (r)
        printf("%d\n", pp);
    return 0;
}
