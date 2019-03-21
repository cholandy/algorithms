#include <cstdio>
#include <deque>

using namespace std;

int a[2000002];
deque<int> d;

int main() {
	int Tn;
	scanf("%d", &Tn);
	while (Tn--) {
		int i, n, r = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			a[i + n] = a[i];
		}
		for (i = 1; i <= n + n; i++) a[i] += a[i - 1];
		while (!d.empty()) d.pop_back();
		d.push_back(0);
		for (i = 1; i <= n + n; i++) {
			while (!d.empty() && d.back() > a[i]) d.pop_back();
			d.push_back(a[i]);
			if (a[i] - d.front() > r) r = a[i] - d.front();
			if (i >= n && d.front() == a[i - n]) d.pop_front();
		}
		printf("%d\n", r);
	}
	return 0;
}