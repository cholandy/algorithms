#include <cstdio>
#include <cstring>

#define fs 2000
#define cs 21
#define ts (fs * cs)

int tc, sn, tn, ta[ts][64], ca[ts][2];
char sa[cs];

int _i(char c) {
    if ('a' <= c)
        return 2 + c - 'a';

    if ('A' <= c)
        return 28 + c - 'A';

    if ('0' <= c)
        return 54 + c - '0';

    if (c == '.')
        return 1;

    return 0;
}

int trv(int t) {
    if (ca[t][0] && !ca[t][1])
        return 1;

    int r = 0;

    for (int n = 0; n < 64; n++)
        if (ta[t][n])
            r += trv(ta[t][n]);

    return r;
}

int main() {
    int i, j, k, n, t;

    for (scanf("%d", &tc); tc--;) {
        memset(ta, 0, sizeof(ta));
        memset(ca, 0, sizeof(ca));

        tn = 0;

        for (i = 0; i < 2; i++) {
            scanf("%d", &sn);

            for (j = 0; j < sn; j++) {
                scanf("%s", sa);

                for (k = t = 0, n = 1; n; k++, t = ta[t][n]) {
                    n = _i(sa[k]);

                    if (!ta[t][n])
                        ta[t][n] = ++tn;

                    ca[t][i]++;
                }

                ca[t][i]++;
            }
        }

        printf("%d\n", trv(0));
    }

    return 0;
}