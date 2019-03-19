#include <cstdio>
#include <vector>

using namespace std;

const int p = 1000000007;

vector<pair<int, int> > g[100001];
int r;

int f(int x, int y) {
	int z, s = 1;
	for (auto t : g[x]) if (t.first != y) {
		z = 1ll * t.second * f(t.first, x) % p;
		r = (r + 1ll * s * z) % p;
		s = (s + z) % p;
	}
	return s;
}

int main() {
	int i, j, k, n;
	scanf("%d", &n);
	while (--n) {
		scanf("%d%d%d", &i, &j, &k);
		g[i].emplace_back(j, k);
		g[j].emplace_back(i, k);
	}
	f(1, 1);
	printf("%d", r);
	return 0;
}
