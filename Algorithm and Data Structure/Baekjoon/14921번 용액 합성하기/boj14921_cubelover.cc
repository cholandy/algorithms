#pragma GCC optimize("Ofast")
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

using namespace std;

char *p;

inline int readInt() {
	int t, r;
	if ((t = *p++ - 48) == -3) {
		for (r = *p++ - 48; (t = *p++ - 48) >= 0; r = r * 10 + t);
		return -r;
	}
	while ((r = *p++ - 48) >= 0) t = t * 10 + r;
	return t;
}

int a[100001];

int main() {
	struct stat buf;
	fstat(0, &buf);
	p = (char *)mmap(0, buf.st_size, PROT_READ, MAP_SHARED, 0, 0);

	int i, j, n, m, r = 1e9;
	n = readInt();
	for (i = 0; i < n; i++) a[i] = readInt();
	sort(a, a + n);
	i = 0; j = n - 1;
	while (i < j) {
		if (abs(r) > abs(a[i] + a[j])) r = a[i] + a[j];
		if (a[i] + a[j] > 0) j--;
		else i++;
	}
	printf("%d\n", r);
	return 0;
}
