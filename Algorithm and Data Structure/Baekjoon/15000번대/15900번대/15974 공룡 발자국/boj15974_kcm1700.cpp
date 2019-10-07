#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <limits>
using namespace std;

struct coord_t {
    int x, y;
    int ind;
    bool operator == (const coord_t & other) const {
        return make_pair(x, y) == make_pair(other.x, other.y);
    }
};

// positive -> left turn
template < typename T >
    int ccw(const T & a,
        const T & b,
            const T & c) {
        long long x1 = b.x - a.x;
        long long y1 = b.y - a.y;
        long long x2 = c.x - a.x;
        long long y2 = c.y - a.y;
        long long res = x1 * y2 - x2 * y1;
        return (res > 0) - (res < 0);
    }

template < typename T >
    struct Sorter {
        T base;

        bool operator()(const T & a,
            const T & b) const {
            if (a == base) return true;
            if (b == base) return false;
            int res = ccw(base, a, b);
            if (res == 0) {
                long long x1 = a.x - base.x;
                long long y1 = a.y - base.y;
                long long x2 = b.x - base.x;
                long long y2 = b.y - base.y;
                return x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2;
            }
            return res > 0;
        }
    };

struct dpnode {
    int dat_ind;
    int cnt;
    // prev_dat_ind, prev_dp_subind
    pair < int, int > prev;
    dpnode(): dat_ind(0), cnt(0), prev(0, 0) {}
    dpnode(int dat_ind, int cnt, pair < int, int > prev): dat_ind(dat_ind), cnt(cnt), prev(prev) {}
};

int main() {
    int n;
    scanf("%d", & n);
    vector < coord_t > dat(n);
    coord_t base;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", & dat[i].x, & dat[i].y);
        if (i == 0 || dat[i].y < base.y) {
            base = dat[i];
        }
    } {
        Sorter < coord_t > st;
        st.base = base;
        sort(dat.begin(), dat.end(), st);
        for (int i = 0; i < n; i++) {
            dat[i].ind = i;
        }
    }

    vector < vector < dpnode >> dpout(n);
    vector < vector < dpnode >> dpin(n);
    int ans = 0;
    pair < int, int > ansp;
    for (int i = 1; i < n; i++) {
        int limit = i - 1;
        for (; limit > 0 && ccw(dat[i], dat[limit], base) == 0; limit--);
        vector < coord_t > points(dat.begin() + 1, dat.begin() + (limit + 1)); {
            Sorter < coord_t > pst;
            pst.base = dat[i];
            sort(points.begin(), points.end(), pst);
        }
        dpout[i].emplace_back(0, 2, make_pair(0, -1));
        for (int jj = 0, rotation_best = 2; jj < points.size(); jj++) {
            int j = points[jj].ind;
            if (dpin[j].empty()) continue;
            int low = 0, high = dpin[j].size() - 1;
            int best = 0;
            int bestind;
            while (low <= high) {
                int mid = (low + high) / 2;
                int pprev = dpin[j][mid].dat_ind, pcnt = dpin[j][mid].cnt;
                if (ccw(dat[i], dat[j], dat[pprev]) > 0) {
                    best = max(best, pcnt + 1);
                    bestind = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (best > rotation_best) {
                rotation_best = best;
                dpout[i].emplace_back(j, best, make_pair(j, bestind));
                if (best > ans) {
                    ans = best;
                    ansp = make_pair(i, dpout[i].size() - 1);
                }
            }
        }
        for (int jj = points.size(), rotation_best = 0; jj-- > 0;) {
            int j = points[jj].ind;
            if (dpout[j].empty()) continue;
            int low = 0, high = dpout[j].size() - 1;
            int best = 0;
            int bestind;
            while (low <= high) {
                int mid = (low + high) / 2;
                int pprev = dpout[j][mid].dat_ind, pcnt = dpout[j][mid].cnt;
                if (ccw(dat[i], dat[j], dat[pprev]) < 0) {
                    best = max(best, pcnt + 1);
                    bestind = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (best > rotation_best) {
                rotation_best = best;
                dpin[i].emplace_back(j, best, make_pair(j, bestind));
            }
        }
        reverse(dpin[i].begin(), dpin[i].end());
    }
    if (ans >= 4) {
        vector < coord_t > points;
        for (;;) {
            points.push_back(dat[ansp.first]);
            if (ansp.first == 0) break;
            if (ans % 2 == 0) {
                ansp = dpout[ansp.first][ansp.second].prev;
            } else {
                ansp = dpin[ansp.first][ansp.second].prev;
            }
            ans--;
        }
        reverse(points.begin(), points.end());
        printf("%d\n", (int) points.size());
        for (auto p: points) {
            printf("%d %d\n", p.x, p.y);
        }
    } else {
        printf("0\n");
    }
    return 0;
}