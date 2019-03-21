#pragma GCC optimize("Ofast")
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

using namespace std;

char *p;

inline int readInt() {
	int t, r;
	for (r = *p++ - 48; (t = *p++ - 48) >= 0; r = r * 10 + t);
	return r;
}

vector<int> g[100001];
int a[300003][2];
int c[100001];
int d[100001];

void f(int x) {
	for (auto t : g[x]) {
		if (!d[t]) f(t);
		if (d[t] > d[x]) d[x] = d[t];
	}
	d[x]++;
}

int main() {
	struct stat buf;
	fstat(0, &buf);
	p = (char *)mmap(0, buf.st_size, PROT_READ, MAP_SHARED, 0, 0);

	int i, j, n, m;
	n = readInt(); m = readInt();
	for (i = 0; i < m; i++) {
		a[i][0] = readInt(); a[i][1] = readInt();
		c[a[i][0]]++;
		c[a[i][1]]++;
	}
	for (i = 0; i < m; i++) {
		if (c[a[i][0]] > c[a[i][1]]) g[a[i][0]].push_back(a[i][1]);
		if (c[a[i][0]] < c[a[i][1]]) g[a[i][1]].push_back(a[i][0]);
	}
	for (i = 0; i < n; i++) if (!d[i]) f(i);
	printf("%d\n", *max_element(d, d + n));
	return 0;
}
