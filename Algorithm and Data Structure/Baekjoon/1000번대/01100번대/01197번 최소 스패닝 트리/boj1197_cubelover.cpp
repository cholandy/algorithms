#include <cstdio>
#include <algorithm>

using namespace std;

char buf[65537], *p = buf + 65536;

inline char getch() {
	if (p == buf + 65536) buf[fread(p = buf, 1, 65536, stdin)] = 10;
	return *p++;
}

inline int get() {
	int t, r;
	r = getch() & 15;
	while ((t = getch()) > 32) r = r * 10 + (t & 15);
	return r;
}

inline int get2() {
	int t, r, f;
	r = getch();
	if (r == 45) {
		f = 1;
		r = getch() & 15;
	}
	else {
		f = 0;
		r &= 15;
	}
	while ((t = getch()) != 10) r = r * 10 + (t & 15);
	return f ? -r : r;
}

pair<int, pair<int, int> > a[100001];
int c[2048];
int d[100001];
int r[100001];
int q[10001];

int f(int x) {
	return x == q[x] ? x : q[x] = f(q[x]);
}

int main() {
	long long s = 0;
	int i, j, n, m;
	n = get();
	m = get();
	for (i = 0; i < m; i++) {
		a[i].second.first = get();
		a[i].second.second = get();
		a[i].first = get2() + 1048576;
		c[a[i].first & 2047]++;
	}
	for (i = 1; i < 2048; i++) c[i] += c[i - 1];
	for (i = 0; i < m; i++) d[--c[a[i].first & 2047]] = i;
	for (i = 0; i < 2048; i++) c[i] = 0;
	for (i = 0; i < m; i++) c[a[i].first >> 11]++;
	for (i = 1; i < 2048; i++) c[i] += c[i - 1];
	for (i = m; i--; r[--c[a[d[i]].first >> 11]] = d[i]);
	for (i = 1; i <= n; i++) q[i] = i;
	for (i = 0; i < m; i++) if (f(a[r[i]].second.first) != f(a[r[i]].second.second)) {
		q[f(a[r[i]].second.first)] = f(a[r[i]].second.second);
		s += a[r[i]].first - 1048576;
	}
	printf("%lld", s);
}