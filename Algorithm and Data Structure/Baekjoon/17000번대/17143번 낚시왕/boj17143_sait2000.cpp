#include <cstdio>
#include <algorithm>
#include <utility>

using std::scanf;
using std::printf;
using std::swap;
using std::pair;

typedef pair<int, int> pii;

const int VERTICAL = 2;
const int HORIZONTAL = 3;

struct shark {
    int r;
    int c;
    int s;
    int d;
    int z;
};

int width;
int height;

int board[100][100];

shark shs[10000];

inline pii calc_pos(const shark& sh, int t) {
    int r = sh.r;
    int c = sh.c;
    int s = sh.s;
    int d = sh.d;

    if (d == VERTICAL) {
        r = (r + t * s) % (2 * height);
        if (r > height) r = 2 * height - r;
    } else {
        c = (c + t * s) % (2 * width);
        if (c > width) c = (2 * width) - c;
    }

    return {r, c};
}

inline int readint() { int n; scanf("%d", &n); return n; }

int main() {
    height = readint() - 1;
    width = readint() - 1;
    int m = readint();

    for (int i = 0; i < m; ++i) {
        int r = readint() - 1;
        int c = readint() - 1;
        int s = readint();
        int d = readint();
        int z = readint();
        if (d % 3 == 1) {
            d = (d-1 ^ 1) + 1;
            if (d == VERTICAL) {
                r = r ? 2 * height - r : 0;
            } else {
                c = c ? 2 * width - c : 0;
            }
        }
        shs[i].r = r;
        shs[i].c = c;
        shs[i].s = s;
        shs[i].d = d;
        shs[i].z = z;
    }

    long long res = 0;

    int ibs = 1;
    for (int t = 0; t <= width; ++t) {
        int tr = height + 1;
        int ti = -1;
        for (int i = 0; i < m; ) {
            shark& sh = shs[i];
            pii pos = calc_pos(sh, t);
            int r = pos.first;
            int c = pos.second;
            if (board[r][c] >= ibs) {
                int j = board[r][c] - ibs;
                if (shs[j].z < sh.z) swap(shs[j], sh);
                swap(sh, shs[--m]);
            } else {
                board[r][c] = i + ibs;
                if (c == t && r < tr) tr = r, ti = i;
                ++i;
            }
        }
        ibs += m;
        if (ti > -1) {
            res += shs[ti].z;
            swap(shs[ti], shs[--m]);
        }
    }

    printf("%lld\n", res);

    return 0;
}
